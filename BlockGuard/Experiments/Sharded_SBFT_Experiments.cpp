//
//  Sharded_SBFT_Experiments.cpp
//  BlockGuard
//
//  Created by Kendric Hood on 7/9/19.
//  Copyright © 2019 Kent State University. All rights reserved.
//

#include "Sharded_SBFT_Experiments.hpp"

///////////////////////////////////////////////////////////////////////////////////////////
//
//
void SBFTCommitteeSizeVsSecurityAndThoughput(std::ofstream &csv, std::ofstream &log){
    std::string header = "Committee Size,totalDef,totalHonest, Ratio Defeated Committees, Confirmed/Submitted, Average Wiating Time";
    csv<< header<< std::endl;
    
    // sec lvl 1
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        int secLvel = system.securityLevel1();
        
        int totalSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%2){
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
        double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double ratioOfDefToHonest = totalDef / totalHonest;
        double waitingTime = waitTime(system.getGlobalLedger());
        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< ratioOfDefToHonest << ","<< double(system.getGlobalLedger().size()) / totalSub<< ","<< waitingTime<<std::endl;
    } // end loop runs
    
    // sec lvl 2
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        int secLvel = system.securityLevel2();
        
        int totalSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%2){
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
        double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double ratioOfDefToHonest = totalDef / totalHonest;
        double waitingTime = waitTime(system.getGlobalLedger());
        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< ratioOfDefToHonest << ","<< double(system.getGlobalLedger().size()) / totalSub<< ","<< waitingTime<<std::endl;
    } // end loop runs
    
    // sec lvl 3
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        int secLvel = system.securityLevel3();
        
        int totalSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%2){
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
        double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double ratioOfDefToHonest = totalDef / totalHonest;
        double waitingTime = waitTime(system.getGlobalLedger());
        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< ratioOfDefToHonest << ","<< double(system.getGlobalLedger().size()) / totalSub<< ","<< waitingTime<<std::endl;
    } // end loop runs
    
    // sec lvl 4
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        int secLvel = system.securityLevel4();
        
        int totalSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%2){
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
        double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double ratioOfDefToHonest = totalDef / totalHonest;
        double waitingTime = waitTime(system.getGlobalLedger());
        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< ratioOfDefToHonest << ","<< double(system.getGlobalLedger().size()) / totalSub<< ","<< waitingTime<<std::endl;
    } // end loop runs
    
    // sec lvl 5
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        int secLvel = system.securityLevel5();
        
        int totalSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%2){
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
        double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double ratioOfDefToHonest = totalDef / totalHonest;
        double waitingTime = waitTime(system.getGlobalLedger());
        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< ratioOfDefToHonest << ","<< double(system.getGlobalLedger().size()) / totalSub<< ","<< waitingTime<<std::endl;
    } // end loop runs
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//
void SBFTWaitingTimeThroughputVsDelay(std::ofstream &csv, std::ofstream &log){
    int delay = 0;
    std::string header = "Round, Confirmed/Submitted, Average Waiting Time,  delay";
    csv<< header<< std::endl;

    // delay 1
    delay = 1;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setMaxDelay(delay);
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(NUMBER_OF_BYZ);
        
        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%2){
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
                double last100RoundCon = totalNumberOfHonestCommittees(system.getGlobalLedger()) - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double waitingTime = waitTimeRolling(system.getGlobalLedger(),i-WINDOW_SIZE);
                csv<< i<< ","<< last100RoundCon / last100RoundSub<< ","<< waitingTime<< ","<<delay<< std::endl;
                prvConfirmed = totalNumberOfHonestCommittees(system.getGlobalLedger());
                prvSub = totalSub;
            }
        }
        double last100RoundCon = totalNumberOfHonestCommittees(system.getGlobalLedger()) - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double waitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< last100RoundCon / last100RoundSub<< ","<< waitingTime<< ","<<delay<< std::endl;
    }// end loop runs
    
    // delay 3
    delay = 2;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setMaxDelay(delay);
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(NUMBER_OF_BYZ);
        
        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%2){
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
                double last100RoundCon = totalNumberOfHonestCommittees(system.getGlobalLedger()) - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double waitingTime = waitTimeRolling(system.getGlobalLedger(),i-WINDOW_SIZE);
                csv<< i<< ","<< last100RoundCon / last100RoundSub<< ","<< waitingTime<< ","<<delay<< std::endl;
                prvConfirmed = totalNumberOfHonestCommittees(system.getGlobalLedger());
                prvSub = totalSub;
            }
        }
        double last100RoundCon = totalNumberOfHonestCommittees(system.getGlobalLedger()) - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double waitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< last100RoundCon / last100RoundSub<< ","<< waitingTime<< ","<<delay<< std::endl;
    }// end loop runs
    
    // delay 5
    delay = 3;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setMaxDelay(delay);
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(NUMBER_OF_BYZ);
        
        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%2){
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
                double last100RoundCon = totalNumberOfHonestCommittees(system.getGlobalLedger()) - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double waitingTime = waitTimeRolling(system.getGlobalLedger(),i-WINDOW_SIZE);
                csv<< i<< ","<< last100RoundCon / last100RoundSub<< ","<< waitingTime<< ","<<delay<< std::endl;
                prvConfirmed = totalNumberOfHonestCommittees(system.getGlobalLedger());
                prvSub = totalSub;
            }
        }
        double last100RoundCon = totalNumberOfHonestCommittees(system.getGlobalLedger()) - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double waitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< last100RoundCon / last100RoundSub<< ","<< waitingTime<< ","<<delay<< std::endl;
    }// end loop runs
    
    // delay 10
    delay = 4;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setMaxDelay(delay);
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(NUMBER_OF_BYZ);
        
        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%2){
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
                double last100RoundCon = totalNumberOfHonestCommittees(system.getGlobalLedger()) - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double waitingTime = waitTimeRolling(system.getGlobalLedger(),i-WINDOW_SIZE);
                csv<< i<< ","<< last100RoundCon / last100RoundSub<< ","<< waitingTime<< ","<<delay<< std::endl;
                prvConfirmed = totalNumberOfHonestCommittees(system.getGlobalLedger());
                prvSub = totalSub;
            }
        }
        double last100RoundCon = totalNumberOfHonestCommittees(system.getGlobalLedger()) - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double waitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< last100RoundCon / last100RoundSub<< ","<< waitingTime<< ","<<delay<< std::endl;
    }// end loop runs

    delay = 5;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setMaxDelay(delay);
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(NUMBER_OF_BYZ);

        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%2){
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
                double last100RoundCon = totalNumberOfHonestCommittees(system.getGlobalLedger()) - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double waitingTime = waitTimeRolling(system.getGlobalLedger(),i-WINDOW_SIZE);
                csv<< i<< ","<< last100RoundCon / last100RoundSub<< ","<< waitingTime<< ","<<delay<< std::endl;
                prvConfirmed = totalNumberOfHonestCommittees(system.getGlobalLedger());
                prvSub = totalSub;
            }
        }
        double last100RoundCon = totalNumberOfHonestCommittees(system.getGlobalLedger()) - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double waitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< last100RoundCon / last100RoundSub<< ","<< waitingTime<< ","<<delay<< std::endl;
    }// end loop runs
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//
void SBFTWaitingTimeThroughputVsByzantine(std::ofstream &csv, std::ofstream &log){
    double byzantine = 0.0;
    // byzantine 1/10
    byzantine = 0.1;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(PEER_COUNT*byzantine);

        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        std::string header = "Round,Waiting Time, Confirmed/Submitted, totalDef, totalHonest, Ratio,  Byzantine";
        csv<< header<< std::endl;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(PEER_COUNT*byzantine);
            if(i%2){
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
                double last100RoundCon = (totalNumberOfHonestCommittees(system.getGlobalLedger())) - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double totalDef = defeatedTrnasactions(system.getGlobalLedger());
                double totalHonest = totalNumberOfHonestCommittees(system.getGlobalLedger());
                double waitingTime = waitTimeRolling(system.getGlobalLedger(),i-WINDOW_SIZE);
                csv<< i<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
                prvConfirmed = totalNumberOfHonestCommittees(system.getGlobalLedger());
                prvSub = totalSub;
            }
        }
        double last100RoundCon = totalNumberOfHonestCommittees(system.getGlobalLedger()) - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double totalDef = defeatedTrnasactions((system.getGlobalLedger()));
        double totalHonest = totalNumberOfHonestCommittees(system.getGlobalLedger());
        double waitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
    }// end loop runs

    // byzantine 1/5
    byzantine = 0.15;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(PEER_COUNT*byzantine);
        
        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(PEER_COUNT*byzantine);
            if(i%2){
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
                double last100RoundCon = (totalNumberOfHonestCommittees(system.getGlobalLedger())) - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double totalDef = defeatedTrnasactions(system.getGlobalLedger());
                double totalHonest = totalNumberOfHonestCommittees(system.getGlobalLedger());
                double waitingTime = waitTimeRolling(system.getGlobalLedger(),i-WINDOW_SIZE);
                csv<< i<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
                prvConfirmed = totalNumberOfHonestCommittees(system.getGlobalLedger());
                prvSub = totalSub;
            }
        }
        double last100RoundCon = totalNumberOfHonestCommittees(system.getGlobalLedger()) - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double totalDef = defeatedTrnasactions((system.getGlobalLedger()));
        double totalHonest = totalNumberOfHonestCommittees(system.getGlobalLedger());
        double waitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
    }// end loop runs

    // delay 1/3
    byzantine = 0.20;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(PEER_COUNT*byzantine);
        
        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(PEER_COUNT*byzantine);
            if(i%2){
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
                double last100RoundCon = (totalNumberOfHonestCommittees(system.getGlobalLedger())) - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double totalDef = defeatedTrnasactions(system.getGlobalLedger());
                double totalHonest = totalNumberOfHonestCommittees(system.getGlobalLedger());
                double waitingTime = waitTimeRolling(system.getGlobalLedger(),i-WINDOW_SIZE);
                csv<< i<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
                prvConfirmed = totalNumberOfHonestCommittees(system.getGlobalLedger());
                prvSub = totalSub;
            }
        }
        double last100RoundCon = totalNumberOfHonestCommittees(system.getGlobalLedger()) - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double totalDef = defeatedTrnasactions((system.getGlobalLedger()));
        double totalHonest = totalNumberOfHonestCommittees(system.getGlobalLedger());
        double waitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
    }// end loop runs

    // byzantine 1/2
    byzantine = 0.25;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(PEER_COUNT*byzantine);
        
        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(PEER_COUNT*byzantine);
            if(i%2){
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
                double last100RoundCon = (totalNumberOfHonestCommittees(system.getGlobalLedger())) - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double totalDef = defeatedTrnasactions(system.getGlobalLedger());
                double totalHonest = totalNumberOfHonestCommittees(system.getGlobalLedger());
                double waitingTime = waitTimeRolling(system.getGlobalLedger(),i-WINDOW_SIZE);
                csv<< i<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
                prvConfirmed = totalNumberOfHonestCommittees(system.getGlobalLedger());
                prvSub = totalSub;
            }
        }
        double last100RoundCon = totalNumberOfHonestCommittees(system.getGlobalLedger()) - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double totalDef = defeatedTrnasactions((system.getGlobalLedger()));
        double totalHonest = totalNumberOfHonestCommittees(system.getGlobalLedger());
        double waitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
    }// end loop runs

    // byzantine 1/2
    byzantine = 0.3;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(PEER_COUNT*byzantine);

        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(PEER_COUNT*byzantine);
            if(i%2){
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
                double last100RoundCon = (totalNumberOfHonestCommittees(system.getGlobalLedger())) - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double totalDef = defeatedTrnasactions(system.getGlobalLedger());
                double totalHonest = totalNumberOfHonestCommittees(system.getGlobalLedger());
                double waitingTime = waitTimeRolling(system.getGlobalLedger(),i-WINDOW_SIZE);
                csv<< i<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
                prvConfirmed = totalNumberOfHonestCommittees(system.getGlobalLedger());
                prvSub = totalSub;
            }
        }
        double last100RoundCon = totalNumberOfHonestCommittees(system.getGlobalLedger()) - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double totalDef = defeatedTrnasactions((system.getGlobalLedger()));
        double totalHonest = totalNumberOfHonestCommittees(system.getGlobalLedger());
        double waitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
    }// end loop runs

    byzantine = 0.35;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(PEER_COUNT*byzantine);

        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(PEER_COUNT*byzantine);
            if(i%2){
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
                double last100RoundCon = (totalNumberOfHonestCommittees(system.getGlobalLedger())) - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double totalDef = defeatedTrnasactions(system.getGlobalLedger());
                double totalHonest = totalNumberOfHonestCommittees(system.getGlobalLedger());
                double waitingTime = waitTimeRolling(system.getGlobalLedger(),i-WINDOW_SIZE);
                csv<< i<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
                prvConfirmed = totalNumberOfHonestCommittees(system.getGlobalLedger());
                prvSub = totalSub;
            }
        }
        double last100RoundCon = totalNumberOfHonestCommittees(system.getGlobalLedger()) - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double totalDef = defeatedTrnasactions((system.getGlobalLedger()));
        double totalHonest = totalNumberOfHonestCommittees(system.getGlobalLedger());
        double waitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
    }// end loop runs

    byzantine = 0.4;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(PEER_COUNT*byzantine);

        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(PEER_COUNT*byzantine);
            if(i%2){
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
                double last100RoundCon = (totalNumberOfHonestCommittees(system.getGlobalLedger())) - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double totalDef = defeatedTrnasactions(system.getGlobalLedger());
                double totalHonest = totalNumberOfHonestCommittees(system.getGlobalLedger());
                double waitingTime = waitTimeRolling(system.getGlobalLedger(),i-WINDOW_SIZE);
                csv<< i<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
                prvConfirmed = totalNumberOfHonestCommittees(system.getGlobalLedger());
                prvSub = totalSub;
            }
        }
        double last100RoundCon = totalNumberOfHonestCommittees(system.getGlobalLedger()) - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double totalDef = defeatedTrnasactions((system.getGlobalLedger()));
        double totalHonest = totalNumberOfHonestCommittees(system.getGlobalLedger());
        double waitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
    }// end loop runs

    byzantine = 0.45;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(PEER_COUNT*byzantine);

        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(PEER_COUNT*byzantine);
            if(i%2){
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
                double last100RoundCon = (totalNumberOfHonestCommittees(system.getGlobalLedger())) - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double totalDef = defeatedTrnasactions(system.getGlobalLedger());
                double totalHonest = totalNumberOfHonestCommittees(system.getGlobalLedger());
                double waitingTime = waitTimeRolling(system.getGlobalLedger(),i-WINDOW_SIZE);
                csv<< i<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
                prvConfirmed = totalNumberOfHonestCommittees(system.getGlobalLedger());
                prvSub = totalSub;
            }
        }
        double last100RoundCon = totalNumberOfHonestCommittees(system.getGlobalLedger()) - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double totalDef = defeatedTrnasactions((system.getGlobalLedger()));
        double totalHonest = totalNumberOfHonestCommittees(system.getGlobalLedger());
        double waitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
    }// end loop runs

    byzantine = 0.5;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(PEER_COUNT*byzantine);

        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(PEER_COUNT*byzantine);
            if(i%2){
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
                double last100RoundCon = (totalNumberOfHonestCommittees(system.getGlobalLedger())) - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double totalDef = defeatedTrnasactions(system.getGlobalLedger());
                double totalHonest = totalNumberOfHonestCommittees(system.getGlobalLedger());
                double waitingTime = waitTimeRolling(system.getGlobalLedger(),i-WINDOW_SIZE);
                csv<< i<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
                prvConfirmed = totalNumberOfHonestCommittees(system.getGlobalLedger());
                prvSub = totalSub;
            }
        }
        double last100RoundCon = totalNumberOfHonestCommittees(system.getGlobalLedger()) - prvConfirmed;
        double last100RoundSub = totalSub - prvSub;
        double totalDef = defeatedTrnasactions((system.getGlobalLedger()));
        double totalHonest = totalNumberOfHonestCommittees(system.getGlobalLedger());
        double waitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS-WINDOW_SIZE);
        csv<< NUMBER_OF_ROUNDS<< ","<< waitingTime<< ","<<last100RoundCon / last100RoundSub<< ","<< totalDef<< ","<< totalHonest<< ","<< totalDef/system.getGlobalLedger().size()<< ","<<byzantine<< std::endl;
    }// end loop runs
}
