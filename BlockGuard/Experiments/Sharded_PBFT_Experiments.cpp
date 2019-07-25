//
//  Sharded_PBFT_Experiments.cpp
//  BlockGuard
//
//  Created by Kendric Hood on 6/20/19.
//  Copyright © 2019 Kent State University. All rights reserved.
//

#include "Sharded_PBFT_Experiments.hpp"

void PBFTCommitteeSizeVsSecurityAndThoughput(std::ofstream &csv, std::ofstream &log){
    std::string header = "Committee Size,totalDef,totalHonest, Ratio Defeated Committees, Confirmed/Submitted, Average Waiting Time";
    csv<< header<< std::endl;
    
    // sec lvl 1
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        PBFTReferenceCommittee system = PBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.setFaultTolerance(FAULT);
        int secLvel = system.securityLevel1();
        
        system.makeByzantines(NUMBER_OF_BYZ);
        int totalSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%2 == 0){
                system.makeRequest(secLvel);
                totalSub++;
            }
            
            system.receive();
            std::cout<< 'r'<< std::flush;
            system.preformComputation();
            std::cout<< 'p'<< std::flush;
            system.transmit();
            std::cout<< 't'<< std::flush;
            
        }
        double totalDef = totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
        double totalHonest = PBFTLedgerToDag(system.getGlobalLedger()).size() - totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
        double ratioOfDefToHonest = totalDef / totalHonest;
        double waitingTime = waitTime(PBFTLedgerToDag(system.getGlobalLedger()));
        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< ratioOfDefToHonest << ","<< double(PBFTLedgerToDag(system.getGlobalLedger()).size()) / totalSub<< ","<< waitingTime<<std::endl;
    } // end loop runs
    
    // sec lvl 2
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        PBFTReferenceCommittee system = PBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.setFaultTolerance(FAULT);
        int secLvel = system.securityLevel2();
        
        system.makeByzantines(NUMBER_OF_BYZ);
        int totalSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%2 == 0){
                system.makeRequest(secLvel);
                totalSub++;
            }
            system.receive();
            std::cout<< 'r'<< std::flush;
            system.preformComputation();
            std::cout<< 'p'<< std::flush;
            system.transmit();
            std::cout<< 't'<< std::flush;
            
        }
        double totalDef = totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
        double totalHonest = PBFTLedgerToDag(system.getGlobalLedger()).size() - totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
        double ratioOfDefToHonest = totalDef / totalHonest;
        double waitingTime = waitTime(PBFTLedgerToDag(system.getGlobalLedger()));
        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< ratioOfDefToHonest << ","<< double(PBFTLedgerToDag(system.getGlobalLedger()).size()) / totalSub<< ","<< waitingTime<<std::endl;
    } // end loop runs
    
    // sec lvl 3
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        PBFTReferenceCommittee system = PBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.setFaultTolerance(FAULT);
        int secLvel = system.securityLevel3();
        
        system.makeByzantines(NUMBER_OF_BYZ);
        int totalSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%2 == 0){
                system.makeRequest(secLvel);
                totalSub++;
            }
            system.receive();
            std::cout<< 'r'<< std::flush;
            system.preformComputation();
            std::cout<< 'p'<< std::flush;
            system.transmit();
            std::cout<< 't'<< std::flush;
            
        }
        double totalDef = totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
        double totalHonest = PBFTLedgerToDag(system.getGlobalLedger()).size() - totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
        double ratioOfDefToHonest = totalDef / totalHonest;
        double waitingTime = waitTime(PBFTLedgerToDag(system.getGlobalLedger()));
        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< ratioOfDefToHonest << ","<< double(PBFTLedgerToDag(system.getGlobalLedger()).size()) / totalSub<< ","<< waitingTime<<std::endl;
    } // end loop runs
    
    // sec lvl 4
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        PBFTReferenceCommittee system = PBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.setFaultTolerance(FAULT);
        int secLvel = system.securityLevel4();
        
        system.makeByzantines(NUMBER_OF_BYZ);
        int totalSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%2 == 0){
                system.makeRequest(secLvel);
                totalSub++;
            }
            system.receive();
            std::cout<< 'r'<< std::flush;
            system.preformComputation();
            std::cout<< 'p'<< std::flush;
            system.transmit();
            std::cout<< 't'<< std::flush;
            
        }
        double totalDef = totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
        double totalHonest = PBFTLedgerToDag(system.getGlobalLedger()).size() - totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
        double ratioOfDefToHonest = totalDef / totalHonest;
        double waitingTime = waitTime(PBFTLedgerToDag(system.getGlobalLedger()));
        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< ratioOfDefToHonest << ","<< double(PBFTLedgerToDag(system.getGlobalLedger()).size()) / totalSub<< ","<< waitingTime<<std::endl;
    } // end loop runs
    
    // sec lvl 5
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        PBFTReferenceCommittee system = PBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.setFaultTolerance(FAULT);
        int secLvel = system.securityLevel5();
        
        system.makeByzantines(NUMBER_OF_BYZ);
        int totalSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%2 == 0){
                system.makeRequest(secLvel);
                totalSub++;
            }
            system.receive();
            std::cout<< 'r'<< std::flush;
            system.preformComputation();
            std::cout<< 'p'<< std::flush;
            system.transmit();
            std::cout<< 't'<< std::flush;
            
        }
        double totalDef = totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
        double totalHonest = PBFTLedgerToDag(system.getGlobalLedger()).size() - totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
        double ratioOfDefToHonest = totalDef / totalHonest;
        double waitingTime = waitTime(PBFTLedgerToDag(system.getGlobalLedger()));
        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< ratioOfDefToHonest << ","<< double(PBFTLedgerToDag(system.getGlobalLedger()).size()) / totalSub<< ","<< waitingTime<<std::endl;
    } // end loop runs
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//
void PBFTWaitingTimeThroughputVsDelay(std::ofstream &csv, std::ofstream &log){
    int delay = 0;
    std::string header = "Round, Confirmed/Submitted, Average Waiting Time,  delay";
    csv<< header<< std::endl;
    
    // delay 1
    delay = 1;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        PBFTReferenceCommittee system = PBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setMaxDelay(delay);
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.setFaultTolerance(FAULT);
        system.makeByzantines(NUMBER_OF_BYZ);
        
        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%2 == 0){
                system.makeRequest();
                totalSub++;
            }
            system.receive();
            std::cout<< 'r'<< std::flush;
            system.preformComputation();
            std::cout<< 'p'<< std::flush;
            system.transmit();
            std::cout<< 't'<< std::flush;
            
            if(i%100 == 0){
                double last100RoundCon = PBFTLedgerToDag(system.getGlobalLedger()).size() - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double waitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),i-WINDOW_SIZE);
                csv<< i<< ","<< last100RoundCon / last100RoundSub<< ","<< waitingTime<< ","<<delay<< std::endl;
                prvConfirmed = PBFTLedgerToDag(system.getGlobalLedger()).size();
                prvSub = totalSub;
            }
        }
        double last100RoundCon = PBFTLedgerToDag(system.getGlobalLedger()).size() - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double waitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< last100RoundCon / last100RoundSub<< ","<< waitingTime<< ","<<delay<< std::endl;
    }// end loop runs
    
    // delay 3
    delay = 3;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        PBFTReferenceCommittee system = PBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setMaxDelay(delay);
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.setFaultTolerance(FAULT);
        system.makeByzantines(NUMBER_OF_BYZ);
        
        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%2 == 0){
                system.makeRequest();
                totalSub++;
            }
            system.receive();
            std::cout<< 'r'<< std::flush;
            system.preformComputation();
            std::cout<< 'p'<< std::flush;
            system.transmit();
            std::cout<< 't'<< std::flush;
            
            if(i%100 == 0){
                double last100RoundCon = PBFTLedgerToDag(system.getGlobalLedger()).size() - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double waitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),i-WINDOW_SIZE);
                csv<< i<< ","<< last100RoundCon / last100RoundSub<< ","<< waitingTime<< ","<<delay<< std::endl;
                prvConfirmed = PBFTLedgerToDag(system.getGlobalLedger()).size();
                prvSub = totalSub;
            }
        }
        double last100RoundCon = PBFTLedgerToDag(system.getGlobalLedger()).size() - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double waitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< last100RoundCon / last100RoundSub<< ","<< waitingTime<< ","<<delay<< std::endl;
    }// end loop runs
    
    // delay 5
    delay = 5;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        PBFTReferenceCommittee system = PBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setMaxDelay(delay);
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.setFaultTolerance(FAULT);
        system.makeByzantines(NUMBER_OF_BYZ);
        
        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%2 == 0){
                system.makeRequest();
                totalSub++;
            }
            system.receive();
            std::cout<< 'r'<< std::flush;
            system.preformComputation();
            std::cout<< 'p'<< std::flush;
            system.transmit();
            std::cout<< 't'<< std::flush;
            
            if(i%100 == 0){
                double last100RoundCon = PBFTLedgerToDag(system.getGlobalLedger()).size() - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double waitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),i-WINDOW_SIZE);
                csv<< i<< ","<< last100RoundCon / last100RoundSub<< ","<< waitingTime<< ","<<delay<< std::endl;
                prvConfirmed = PBFTLedgerToDag(system.getGlobalLedger()).size();
                prvSub = totalSub;
            }
        }
        double last100RoundCon = PBFTLedgerToDag(system.getGlobalLedger()).size() - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double waitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< last100RoundCon / last100RoundSub<< ","<< waitingTime<< ","<<delay<< std::endl;
    }// end loop runs
    
    // delay 10
    delay = 10;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        PBFTReferenceCommittee system = PBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setMaxDelay(delay);
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.setFaultTolerance(FAULT);
        system.makeByzantines(NUMBER_OF_BYZ);
        
        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%2 == 0){
                system.makeRequest();
                totalSub++;
            }
            system.receive();
            std::cout<< 'r'<< std::flush;
            system.preformComputation();
            std::cout<< 'p'<< std::flush;
            system.transmit();
            std::cout<< 't'<< std::flush;
            
            if(i%100 == 0){
                double last100RoundCon = PBFTLedgerToDag(system.getGlobalLedger()).size() - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double waitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),i-WINDOW_SIZE);
                csv<< i<< ","<< last100RoundCon / last100RoundSub<< ","<< waitingTime<< ","<<delay<< std::endl;
                prvConfirmed = PBFTLedgerToDag(system.getGlobalLedger()).size();
                prvSub = totalSub;
            }
        }
        double last100RoundCon = PBFTLedgerToDag(system.getGlobalLedger()).size() - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double waitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< last100RoundCon / last100RoundSub<< ","<< waitingTime<< ","<<delay<< std::endl;
    }// end loop runs
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//
void PBFTWaitingTimeThroughputVsByzantine(std::ofstream &csv, std::ofstream &log){
    double byzantine = 0.0;

    // byzantine 1/10
    byzantine = 0.05;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        PBFTReferenceCommittee system = PBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.setFaultTolerance(FAULT);
        system.makeByzantines(PEER_COUNT*byzantine);
        
        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        std::string header = "Round,Waiting Time, Confirmed/Submitted, totalDef, totalHonest, Ratio,  Byzantine";
        csv<< header<< std::endl;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(PEER_COUNT*byzantine);
            if(i%2 == 0){
                system.makeRequest();
                totalSub++;
            }
            system.receive();
            std::cout<< 'r'<< std::flush;
            system.preformComputation();
            std::cout<< 'p'<< std::flush;
            system.transmit();
            std::cout<< 't'<< std::flush;
            
            if(i%100 == 0){
                double last100RoundCon = PBFTLedgerToDag(system.getGlobalLedger()).size() - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double totalDef = defeatedTrnasactions(PBFTLedgerToDag(system.getGlobalLedger()));
                double totalHonest = system.getGlobalLedger().size() - totalDef;
                double waitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),i-WINDOW_SIZE);
                csv<< i<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
                prvConfirmed = PBFTLedgerToDag(system.getGlobalLedger()).size();
                prvSub = totalSub;
            }
        }
        double last100RoundCon = PBFTLedgerToDag(system.getGlobalLedger()).size() - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double totalDef = defeatedTrnasactions(PBFTLedgerToDag(system.getGlobalLedger()));
        double totalHonest = system.getGlobalLedger().size() - totalDef;
        double waitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
    }// end loop runs
    
    // byzantine 1/5
    byzantine = 0.1;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        PBFTReferenceCommittee system = PBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(PEER_COUNT*byzantine);
        system.setFaultTolerance(FAULT);
        
        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(PEER_COUNT*byzantine);
            if(i%2 == 0){
                system.makeRequest();
                totalSub++;
            }
            system.receive();
            std::cout<< 'r'<< std::flush;
            system.preformComputation();
            std::cout<< 'p'<< std::flush;
            system.transmit();
            std::cout<< 't'<< std::flush;

            if(i%100 == 0){
                double last100RoundCon = PBFTLedgerToDag(system.getGlobalLedger()).size() - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double totalDef = defeatedTrnasactions(PBFTLedgerToDag(system.getGlobalLedger()));
                double totalHonest = system.getGlobalLedger().size() - totalDef;
                double waitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),i-WINDOW_SIZE);
                csv<< i<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
                prvConfirmed = PBFTLedgerToDag(system.getGlobalLedger()).size();
                prvSub = totalSub;
            }
        }
        double last100RoundCon = PBFTLedgerToDag(system.getGlobalLedger()).size() - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double totalDef = defeatedTrnasactions(PBFTLedgerToDag(system.getGlobalLedger()));
        double totalHonest = system.getGlobalLedger().size() - totalDef;
        double waitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
    }// end loop runs
    
    // delay 1/3
    byzantine = 0.25;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        PBFTReferenceCommittee system = PBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(PEER_COUNT*byzantine);
        system.setFaultTolerance(FAULT);
        
        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(PEER_COUNT*byzantine);
            if(i%2 == 0){
                system.makeRequest();
                totalSub++;
            }
            system.receive();
            std::cout<< 'r'<< std::flush;
            system.preformComputation();
            std::cout<< 'p'<< std::flush;
            system.transmit();
            std::cout<< 't'<< std::flush;

            if(i%100 == 0){
                double last100RoundCon = PBFTLedgerToDag(system.getGlobalLedger()).size() - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double totalDef = defeatedTrnasactions(PBFTLedgerToDag(system.getGlobalLedger()));
                double totalHonest = system.getGlobalLedger().size() - totalDef;
                double waitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),i-WINDOW_SIZE);
                csv<< i<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
                prvConfirmed = PBFTLedgerToDag(system.getGlobalLedger()).size();
                prvSub = totalSub;
            }
        }
        double last100RoundCon = PBFTLedgerToDag(system.getGlobalLedger()).size() - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double totalDef = defeatedTrnasactions(PBFTLedgerToDag(system.getGlobalLedger()));
        double totalHonest = system.getGlobalLedger().size() - totalDef;
        double waitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
    }// end loop runs
    
    // byzantine 1/2
    byzantine = 0.3;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        PBFTReferenceCommittee system = PBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(PEER_COUNT*byzantine);
        system.setFaultTolerance(FAULT);
        
        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(PEER_COUNT*byzantine);
            if(i%2 == 0){
                system.makeRequest();
                totalSub++;
            }
            system.receive();
            std::cout<< 'r'<< std::flush;
            system.preformComputation();
            std::cout<< 'p'<< std::flush;
            system.transmit();
            std::cout<< 't'<< std::flush;

            if(i%100 == 0){
                double last100RoundCon = PBFTLedgerToDag(system.getGlobalLedger()).size() - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double totalDef = defeatedTrnasactions(PBFTLedgerToDag(system.getGlobalLedger()));
                double totalHonest = system.getGlobalLedger().size() - totalDef;
                double waitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),i-WINDOW_SIZE);
                csv<< i<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
                prvConfirmed = PBFTLedgerToDag(system.getGlobalLedger()).size();
                prvSub = totalSub;
            }
        }
        double last100RoundCon = PBFTLedgerToDag(system.getGlobalLedger()).size() - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double totalDef = defeatedTrnasactions(PBFTLedgerToDag(system.getGlobalLedger()));
        double totalHonest = system.getGlobalLedger().size() - totalDef;
        double waitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
    }// end loop runs
}

////////////////////////////////////////////////////////////
// util
//
std::vector<DAGBlock> PBFTLedgerToDag(std::vector<ledgerEntery> PBFTLedger){
    std::vector<DAGBlock> newDag;
    for(int i = 0; i < PBFTLedger.size(); i++){
        newDag.push_back(PBFTLedger[i].first.toDAGBlock());
    }
    return newDag;
}
