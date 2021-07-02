//
//  LinearPeer.hpp
//  BlockGuard
//
//  Created by Joseph Oglio on 6/15/21.
//  Copyright © 2019 Kent State University. All rights reserved.
//

#ifndef LinearCoronaPeer_hpp
#define LinearCoronaPeer_hpp

#include "./Common/Peer.hpp"

struct LinearCoronaMessage {
    std::string reqId;
    std::string action; // options are R, N
    int roundSubmitted;
};

class LinearCoronaPeer : public Peer<LinearCoronaMessage>{
protected:
    int counter;
public:
    // methods that must be defined when deriving from Peer
    LinearCoronaPeer                              (std::string);
    LinearCoronaPeer                              (const LinearCoronaPeer &rhs);
    ~LinearCoronaPeer                             ();
    std::string left      = "MIN";
    std::string right     = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
    int requestsSatisfied = 0;
    int latency           = 0;
    bool alive            = false;
    void                 heartBeat();
    void                 preformComputation ();
    void                 makeRequest        (){};
    void                 sendMessage        (std::string peer, LinearCoronaMessage message);
    void                 log                ()const{printTo(*_log);};
    std::ostream&        printTo            (std::ostream&)const;
    friend std::ostream& operator<<         (std::ostream&, const LinearCoronaPeer&);

    // its normally a good idea to make some getters and setters for a peer to enable testing 
    //  of the peers state durring an experment and to get metrics. 
    int                  getCounter()const                                      {return counter;};
    void                 setCounter(int c)                                      {counter = c;};
};
#endif LinearCoronaPeer_hpp
