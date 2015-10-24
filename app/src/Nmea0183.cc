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
#include <vector>
#include <sstream>
#include <Logger.h>
#include <Nmea0183.h>

using namespace std;

Nmea0183::Nmea0183() {
    Logger::info("Nmea0183:constructor");
    resetReceiver();
}

Nmea0183::~Nmea0183() {
    Logger::info("Nmea0183:destructor");
    //TODO free memory or something?!
}

void Nmea0183::onDataReceive(char *receivedBytes, int receivedBytesCount) {

    for(int i = 0; i < receivedBytesCount; i++) {
        //Process received bytes one by one
        switch(mReceiverState) {
            case WaitForStartOfMessage:
                //Logger::debug("Nmea0183::onDataReceive:
                //WaitForStartOfMessage");
                switch(receivedBytes[i]) {
                    case START_OF_MESSAGE:
                        //TODO what if this $ belongs to CRC?!
                        mFields.clear();
                        mReceiverState = ReceivingFields;
                        break;
                    default:
                        Logger::error("WaitForStartOfMessage:\
                            Unexpected data received!");
                        //TODO that's it?
                        break;
                }
                break;
            case ReceivingFields:
                //Logger::debug("Nmea0183::onDataReceive: ReceivingFields");
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
                //Logger::debug("Nmea0183::onDataReceive: ReceivingCRCByte0");
                //I reckon we basically should expect any character here.
                mCRC[0] = receivedBytes[i];
                mReceiverState = ReceivingCRCByte1;
                break;
             case ReceivingCRCByte1:
                //Logger::debug("Nmea0183::onDataReceive: ReceivingCRCByte1");
                //I reckon we basically should expect any character here.
                mCRC[1] = receivedBytes[i];
                mReceiverState = ReceivingEndOfMessageByte0;
                break;
            case ReceivingEndOfMessageByte0:
                //Logger::debug("Nmea0183::onDataReceive: ReceivingEndOfMessageByte0")
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
                //Logger::debug("Nmea0183::onDataReceive: ReceivingEndOfMessageByte1");
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
                Logger::error("Nmea0183::onDataReceive: Unknown status!");
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
    vector<string> fields = parseFields(mFields);   //TODO conside queue

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
        Logger::error("Unknown NMEA Message");
    }
}

void Nmea0183::onGGAReceive(std::vector<std::string> dataFields) {
    Logger::info("onGGAReceive");
    string msg = "Fields: ";
    for(vector<string>::iterator it = dataFields.begin(); it != dataFields.end(); it++) {
        msg += *it;
        msg += "  ";
    }
    Logger::info(msg);

}

void Nmea0183::onVTGReceive(std::vector<std::string> dataFields) {
    Logger::info("onVTGReceive");
    string msg = "Fields: ";
    for(vector<string>::iterator it = dataFields.begin(); it != dataFields.end(); it++) {
        msg += *it;
        msg += "  ";
    }
    Logger::info(msg);

}

void Nmea0183::onRMCReceive(std::vector<std::string> dataFields) {
    Logger::info("onRMCReceive");
    string msg = "Fields: ";
    for(vector<string>::iterator it = dataFields.begin(); it != dataFields.end(); it++) {
        msg += *it;
        msg += "  ";
    }
    Logger::info(msg);

}

void Nmea0183::onGSVReceive(std::vector<std::string> dataFields) {
    Logger::info("onGSVReceive");
    string msg = "Fields: ";
    for(vector<string>::iterator it = dataFields.begin(); it != dataFields.end(); it++) {
        msg += *it;
        msg += "  ";
    }
    Logger::info(msg);

}

void Nmea0183::onGLLReceive(std::vector<std::string> dataFields) {
    Logger::info("onGLLReceive");
}

void Nmea0183::onGSAReceive(std::vector<std::string> dataFields)  {
    Logger::info("onGSAReceive");
}

void Nmea0183::onMSSReceive(std::vector<std::string> dataFields) {
    Logger::info("onMSSReceive");
}

void Nmea0183::onZDAReceive(std::vector<std::string> dataFields) {
    Logger::info("onZDAReceive");
}

void Nmea0183::onPSRF140Receive(std::vector<std::string> dataFields) {
    Logger::info("onPSRF140Receive");
}

void Nmea0183::onPSRF150Receive(std::vector<std::string> dataFields) {
    Logger::info("onPSRF150Receive");
}

void Nmea0183::onPSRF151Receive(std::vector<std::string> dataFields) {
    Logger::info("onPSRF151Receive");
}

void Nmea0183::onPSRF152Receive(std::vector<std::string> dataFields) {
    Logger::info("onPSRF152Receive");
}

void Nmea0183::onPSRF154Receive(std::vector<std::string> dataFields) {
    Logger::info("onPSRF154Receive");
}

void Nmea0183::onPSRF155Receive(std::vector<std::string> dataFields) {
    Logger::info("onPSRF155Receive");
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
