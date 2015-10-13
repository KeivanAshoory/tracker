/*
 * =============================================================================
 *
 *       Filename:  Nmea0183.cc
 *
 *    Description:  NEMA 0183
 *
 *        Version:  1.0
 *        Created:  10/09/15 19:34:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  none
 *
 * =============================================================================
 */

#include <iostream>
#include <Nmea0183.h>
#include <vector>
#include <sstream>

using namespace std;

Nmea0183::Nmea0183() {
    cout << "Nmea0183:constructor" << endl;
    resetReceiver();
}

Nmea0183::~Nmea0183() {
    cout << "Nmea0183:destructor" << endl;
    //TODO free memory or something?!
}

void Nmea0183::onDataReceive(char *receivedBytes, int receivedBytesCount) {

    for(int i = 0; i < receivedBytesCount; i++) {
        //Process received bytes one by one
        switch(mReceiverState) {
            case WaitForStartOfMessage:
                //cout << "Nmea0183::onDataReceive: WaitForStartOfMessage" << endl;
                switch(receivedBytes[i]) {
                    case START_OF_MESSAGE:
                        //TODO what if this $ belongs to CRC?!
                        mFields.clear();
                        mReceiverState = ReceivingFields;
                        break;
                    default:
                        cout << "WaitForStartOfMessage:\
                            Unexpected data received!" << endl;
                        //TODO that's it?
                        break;
                }
                break;
            case ReceivingFields:
                //cout << "Nmea0183::onDataReceive: ReceivingFields" << endl;
                switch(receivedBytes[i]) {
                    case START_OF_MESSAGE:
                        //Received $ while receiving fields! Lets reset!
                        //TODO That's it? Just reset?!
                        mFields.clear();
                        mReceiverState = ReceivingFields;
                        break;
                    case START_OF_CRC:
                        //End of fields
                        mReceiverState = ReceivingCRCByte0;
                        break;
                    case END_OF_MESSAGE_BYTE0:
                    case END_OF_MESSAGE_BYTE1:
                        //Received EOF while receiving fields!
                        //Ignore the current message
                        mReceiverState = WaitForStartOfMessage;
                        break;
                    default:
                        //Received a normal byte.
                        mFields.push_back(receivedBytes[i]);
                        break;
                }

                break;
            case ReceivingCRCByte0:
                //cout << "Nmea0183::onDataReceive: ReceivingCRCByte0" << endl;
                //I reckon we basically should expect any character here.
                mCRC[0] = receivedBytes[i];
                mReceiverState = ReceivingCRCByte1;
                break;
             case ReceivingCRCByte1:
                //cout << "Nmea0183::onDataReceive: ReceivingCRCByte1" << endl;
                //I reckon we basically should expect any character here.
                mCRC[1] = receivedBytes[i];
                mReceiverState = ReceivingEndOfMessageByte0;
                break;
            case ReceivingEndOfMessageByte0:
                //cout << "Nmea0183::onDataReceive: ReceivingEndOfMessageByte0" << endl;
                switch(receivedBytes[i]) {
                    case END_OF_MESSAGE_BYTE0:
                        mReceiverState = ReceivingEndOfMessageByte1;
                        break;
                    case START_OF_MESSAGE:
                        //Received $ while receiving EOF! Lets reset.
                        //TODO That's it? Just reset?!
                        mFields.clear();
                        mReceiverState = ReceivingFields;
                        break;
                   default:
                        //Ignore the current message
                        mReceiverState = WaitForStartOfMessage;
                        break;
                }

                mReceiverState = ReceivingEndOfMessageByte1;
                break;
            case ReceivingEndOfMessageByte1:
                //cout << "Nmea0183::onDataReceive: ReceivingEndOfMessageByte1" << endl;
                switch(receivedBytes[i]) {
                    case END_OF_MESSAGE_BYTE1:
                        //A whole message received, check CRC.
                        if(validateCRC()) {
                            //CRC check passed.
                            onNmeaMessageReceive();
                        } else {
                            //CRC check failed! Ignore the message.
                        }

                        mReceiverState = WaitForStartOfMessage;
                        break;
                    case START_OF_MESSAGE:
                        //Received $ while receiving EOF! Lets reset.
                        //TODO That's it? Just reset?!
                        mFields.clear();
                        mReceiverState = ReceivingFields;
                        break;
                    default:
                        //Ignore the current message
                        mReceiverState = WaitForStartOfMessage;
                        break;
                }

                break;
            default:
                cout << "Nmea0183::onDataReceive: Unknown status!" << endl;
                //TODO WTF?!
                break;
        }
    }
}

void Nmea0183::resetReceiver() {
    mReceiverState = WaitForStartOfMessage;
    //TODO free memory or something?!
}

void Nmea0183::onNmeaMessageReceive() {
    //cout << "Nmea0183::onNmeaMessageReceive: " << mFields << endl;

    vector<string> fields = parseFields(mFields);   //TODO conside queue


    //cout << "Fileds: " << endl;
    //for(vector<string>::iterator it = fields.begin(); it != fields.end(); it++) {
    //    cout << *it << "\t" << endl;
    //}

    string messageType = fields.front();
    vector<string> dataFields(fields.begin() + 1, fields.end());

    if(messageType == "GPGGA") {
        onGGAReceive(dataFields);
    } else if(messageType == "GPGLL") {
        onGLLReceive(dataFields);
    } else if(messageType == "GPGSA") {
        onGSAReceive(dataFields);
    } else if(messageType == "GPGSV") {
        onGSVReceive(dataFields);
    } else if(messageType == "GPMSS") {
        onMSSReceive(dataFields);
    } else if(messageType == "GPRMC") {
        onRMCReceive(dataFields);
    } else if(messageType == "GPVTG") {
        onVTGReceive(dataFields);
    } else if(messageType == "GPZDA") {
        onZDAReceive(dataFields);
    } else if(messageType == "PSRF140") {
        onPSRF140Receive(dataFields);
    } else if(messageType == "PSRF150") {
        onPSRF150Receive(dataFields);
    } else if(messageType == "PSRF151") {
        onPSRF151Receive(dataFields);
    } else if(messageType == "PSRF152") {
        onPSRF152Receive(dataFields);
    } else if(messageType == "PSRF154") {
        onPSRF154Receive(dataFields);
    } else if(messageType == "PSRF155") {
        onPSRF155Receive(dataFields);
    } else {
        //TODO That's it?
        cout << "Unknown NMEA Message: " << messageType << "!" << endl;
    }
}

void Nmea0183::onGGAReceive(std::vector<std::string> dataFields) {
    cout << "onGGAReceive" << endl;
    cout << "Fields: ";
    for(vector<string>::iterator it = dataFields.begin(); it != dataFields.end(); it++) {
        cout << *it << "  ";
    }
    cout << endl;



}

void Nmea0183::onVTGReceive(std::vector<std::string> dataFields) {
    cout << "onVTGReceive" << endl;
    cout << "Fields: ";
    for(vector<string>::iterator it = dataFields.begin(); it != dataFields.end(); it++) {
        cout << *it << "  ";
    }
    cout << endl;


}

void Nmea0183::onRMCReceive(std::vector<std::string> dataFields) {
    cout << "onRMCReceive" << endl;
    cout << "Fields: ";
    for(vector<string>::iterator it = dataFields.begin(); it != dataFields.end(); it++) {
        cout << *it << "  ";
    }
    cout << endl;


}

void Nmea0183::onGSVReceive(std::vector<std::string> dataFields) {
    cout << "onGSVReceive" << endl;
    cout << "Fields: ";
    for(vector<string>::iterator it = dataFields.begin(); it != dataFields.end(); it++) {
        cout << *it << "  ";
    }
    cout << endl;


}

void Nmea0183::onGLLReceive(std::vector<std::string> dataFields) {
    cout << "onGLLReceive" << endl;
}

void Nmea0183::onGSAReceive(std::vector<std::string> dataFields)  {
    cout << "onGSAReceive" << endl;
}

void Nmea0183::onMSSReceive(std::vector<std::string> dataFields) {
    cout << "onMSSReceive" << endl;
}

void Nmea0183::onZDAReceive(std::vector<std::string> dataFields) {
    cout << "onZDAReceive" << endl;
}

void Nmea0183::onPSRF140Receive(std::vector<std::string> dataFields) {
    cout << "onPSRF140Receive" << endl;
}

void Nmea0183::onPSRF150Receive(std::vector<std::string> dataFields) {
    cout << "onPSRF150Receive" << endl;
}

void Nmea0183::onPSRF151Receive(std::vector<std::string> dataFields) {
    cout << "onPSRF151Receive" << endl;
}

void Nmea0183::onPSRF152Receive(std::vector<std::string> dataFields) {
    cout << "onPSRF152Receive" << endl;
}

void Nmea0183::onPSRF154Receive(std::vector<std::string> dataFields) {
    cout << "onPSRF154Receive" << endl;
}

void Nmea0183::onPSRF155Receive(std::vector<std::string> dataFields) {
    cout << "onPSRF155Receive" << endl;
}

bool Nmea0183::validateCRC() {
    //TODO write code!!
    return true;
}

vector<string> Nmea0183::parseFields(string fields) {
    vector<string> fieldsVector;
    stringstream fieldsStringStream(fields);

    while(fieldsStringStream.good()) {
        string field;
        getline(fieldsStringStream, field, ',');
        fieldsVector.push_back(field);
    }

    return fieldsVector;
}
