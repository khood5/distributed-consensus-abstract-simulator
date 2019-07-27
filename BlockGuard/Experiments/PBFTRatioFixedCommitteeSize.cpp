//
//  PBFTRatioFixedCommitteeSize.cpp
//  BlockGuard
//
//  Created by Kendric Hood on 7/27/19.
//  Copyright © 2019 Kent State University. All rights reserved.
//

#include "PBFTRatioFixedCommitteeSize.hpp"


void PBFTRatioFixedCommitteeSize(std::string filePath){
    std::ofstream csv;
    std::ofstream log;
    log.open(filePath + "pbft_s.log");
    if ( log.fail() ){
        std::cerr << "Error: could not open file: "<< filePath + "PBFTRatioFixedCommitteeSize.log" << std::endl;
    }
    
    csv.open(filePath + "PBFTCommitteeSizeVsSecurityAndThoughput.csv");
    if ( log.fail() ){
        std::cerr << "Error: could not open file: "<< filePath + "PBFTRatioFixedCommitteeSize.csv" << std::endl;
    }
    
    int byz = PEER_COUNT*0.3;
    
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
        
        system.makeByzantines(byz);
        int totalSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(byz);
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
        
        system.makeByzantines(byz);
        int totalSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(byz);
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
        
        system.makeByzantines(byz);
        int totalSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(byz);
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
        
        system.makeByzantines(byz);
        int totalSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(byz);
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
        
        system.makeByzantines(byz);
        int totalSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(byz);
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
    
    csv.close();
}
