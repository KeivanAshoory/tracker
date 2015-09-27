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
    //if(mFields.substr(0,5)=="GPRMC") {
        cout << "Nmea0183::onNmeaMessageReceive: " << mFields << endl;
    //}
    //Write code!
}

bool Nmea0183::validateCRC() {
    //TODO write code!!
    return true;
}
