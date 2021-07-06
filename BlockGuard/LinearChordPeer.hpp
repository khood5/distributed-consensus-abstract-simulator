//
//  LinearPeer.hpp
//  BlockGuard
//
//  Created by Joseph Oglio on 6/15/21.
//  Copyright © 2019 Kent State University. All rights reserved.
//

#ifndef LinearChordPeer_hpp
#define LinearChordPeer_hpp

#include "./Common/Peer.hpp"

struct LinearChordMessage {
    std::string reqId;
    std::string action; // options are R, N
    int roundSubmitted;
};

struct Finger {
    std::string Id;
    int roundUpdated = 0;;
};

class LinearChordPeer : public Peer<LinearChordMessage>{
protected:
    int counter;
public:
    // methods that must be defined when deriving from Peer
    LinearChordPeer                              (std::string);
    LinearChordPeer                              (const LinearChordPeer &rhs);
    ~LinearChordPeer                             ();
    std::vector<Finger> successor;
    std::vector<Finger> predecessor;
    int requestsSatisfied = 0;
    int latency           = 0;
    int redundantSize     = 2;
    bool alive            = false;
    void                 heartBeat();
    void                 preformComputation ();
    void                 makeRequest        (){};
    void                 sendMessage        (std::string peer, LinearChordMessage message);
    void                 log                ()const{printTo(*_log);};
    std::ostream&        printTo            (std::ostream&)const;
    friend std::ostream& operator<<         (std::ostream&, const LinearChordPeer&);

    // its normally a good idea to make some getters and setters for a peer to enable testing 
    //  of the peers state durring an experment and to get metrics. 
    int                  getCounter()const                                      {return counter;};
    void                 setCounter(int c)                                      {counter = c;};
};
#endif LinearChordPeer_hpp
