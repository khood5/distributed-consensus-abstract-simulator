//
//  LinearPeer.cpp
//  BlockGuard
//
//  Created by Joseph Oglio on 6/15/21.//
//  Copyright © 2019 Kent State University. All rights reserved.
//

#include "LinearPeer.hpp"
#include "./Common/Peer.hpp"
#include "./Common/Packet.hpp"
#include <iostream>

LinearPeer::~LinearPeer(){
    
}

LinearPeer::LinearPeer(const LinearPeer &rhs) : Peer<LinearMessage>(rhs){
    counter = rhs.counter;
}

LinearPeer::LinearPeer(std::string id) : Peer(id){
    counter =0;
}

void LinearPeer::preformComputation(){
    for(int i = 0; i < _inStream.size(); i++){
        std::string source = _inStream[i].sourceId();
        LinearMessage message = _inStream[i].getMessage();
        std::string reqId = message.reqId;
        if (message.action == "R") {
            if (_id == reqId) {
                // Node found
                requestsSatisfied++;
                latency += _clock - message.roundSubmitted - 1;
            }
            else if (_id < reqId && reqId < right) {
                //Node gone
                requestsSatisfied++;
                latency += _clock - message.roundSubmitted - 1;
            }
            else if (reqId < _id) {
                sendMessage(left, message);
            }
            else {
                sendMessage(right, message);
            }
        }
        else if (message.action == "join") {
            if (_id < reqId && reqId < right && !leaving && !busy) {
                message.action = "sua";
                message.reqId = right;
                sendMessage(reqId, message);
                reqType = "J";
                busy = true;
            }
            else if (reqId < _id) {
                sendMessage(left, message);
            }
            else {
                sendMessage(right, message);
            }
        }
        else if (message.action == "leave") {
            if (reqId == right && !leaving && !busy) {
                message.action = "sua";
                message.reqId = "";
                sendMessage(message.rightNeighbor, message);
                reqType = "L";
                busy = true;
            }
            else if (reqId == _id) {
                message.rightNeighbor = right;
                sendMessage(left, message);
            }
            else if (reqId < _id) {
                sendMessage(left, message);
            }
            else {
                sendMessage(right, message);
            }
        }
        else if (message.action == "sua") {
            if (reqId != "") {
                right = message.reqId;
                left = source;
                message.reqId = "";
                sendMessage(right, message);
            }
            else {
                left = source;
                message.action = "sub";
                sendMessage(left, message);
            }
        }
        else if (message.action == "sub") {
            if (source != right) {
                message.action = "tda";
                sendMessage(right, message);
                right = source;
            }
            else {
                sendMessage(left, message);
            }
        }
        else if (message.action == "tda") {
            if (source != left) {
                message.action = "tdb";
                sendMessage(source, message);
            }
            else {
                sendMessage(right, message);
            }
        }
        else if (message.action == "tdb") {
            if (source != right) {
                if (reqType == "L") {
                    message.action = "ftd";
                    sendMessage(source, message);
                    reqType = "N";
                    busy = false;
                }
                else {
                    message.action = "ftd";
                    sendMessage(right, message);
                    reqType = "N";
                    busy = false;
                }
            }
            else {
                sendMessage(left, message);
            }
        }
        else if (message.action == "ftd") {
            if (leaving) {
                right = "";
                left = "";
            }
            else {
                busy = false;
            }
            requestsSatisfied++;
            latency += _clock - message.roundSubmitted - 1;
        }
    }
    _inStream.clear();
}

void LinearPeer::sendMessage(std::string peer, LinearMessage message) {
    if (peer == "") {
        std::cout << "dropped a message maybe";
    }
    else if (peer == "ZZZZZZZZZZZZZZZZZZZZZZZZZZZ") {
        std::cout << "dropped a message maybe";
    }
    else {
        Packet<LinearMessage> newMessage(std::to_string(counter), peer, _id);
        newMessage.setBody(message);
        _outStream.push_back(newMessage);
        counter++;
    }
}

std::ostream& LinearPeer::printTo(std::ostream &out)const{
    Peer<LinearMessage>::printTo(out);
    
    out<< _id<< std::endl;
    out<< "counter:"<< counter<< std::endl;
    
    return out;
}

std::ostream& operator<< (std::ostream &out, const LinearPeer &peer){
    peer.printTo(out);
    return out;
}
