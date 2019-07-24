//
// Created by khood on 7/22/19.
//

#include "txRate.h"
#include <cassert>

void txRate(std::ofstream &csv, std::ofstream &log){
//    csv << "PoW"<< std::endl;
//    csv<< "SecLvl,totalDef,totalHonest,avgWaitingTime,thoughtput"<<std::endl;
//    csv << "1 per 4 rounds"<< std::endl;
//    for(int r = 0; r < NUMBER_OF_RUNS; r++){
//        bCoinReferenceCommittee system = bCoinReferenceCommittee();
//        system.setGroupSize(GROUP_SIZE);
//        system.setToRandom();
//        system.setToOne();
//        system.setLog(log);
//        system.initNetwork(PEER_COUNT);
//        system.makeByzantines(NUMBER_OF_BYZ);
//        int secLvel = system.securityLevel1();
//
//        int totalSub = 0;
//        int prvConfirmed = 0;
//        int prvSub = 0;
//        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
//            system.shuffleByzantines(NUMBER_OF_BYZ);
//            if(i%4 == 0){
//                system.makeRequest();
//                totalSub++;
//            }
//            system.receive();
//            std::cout<< 'r'<< std::flush;
//            system.preformComputation();
//            std::cout<< 'p'<< std::flush;
//            system.transmit();
//            std::cout<< 't'<< std::flush;
//            if(i%100 == 0){
//                double last100RoundCon = system.getGlobalLedger().size() - prvConfirmed;
//                double last100RoundSub = totalSub - prvSub;
//                double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//                double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//                double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),i-100);
//                csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//                prvConfirmed = system.getGlobalLedger().size();
//                prvSub = totalSub;
//            }
//
//        }
//        double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//        double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS - 100);
//        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//    }
//
//    csv << "1 every 2 rounds"<< std::endl;
//    for(int r = 0; r < NUMBER_OF_RUNS; r++){
//        bCoinReferenceCommittee system = bCoinReferenceCommittee();
//        system.setGroupSize(GROUP_SIZE);
//        system.setToRandom();
//        system.setToOne();
//        system.setLog(log);
//        system.initNetwork(PEER_COUNT);
//        system.makeByzantines(NUMBER_OF_BYZ);
//        int secLvel = system.securityLevel1();
//
//        int totalSub = 0;
//        int prvConfirmed = 0;
//        int prvSub = 0;
//        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
//            system.shuffleByzantines(NUMBER_OF_BYZ);
//            if(i%2 == 0){
//                system.makeRequest();
//                totalSub++;
//            }
//            system.receive();
//            std::cout<< 'r'<< std::flush;
//            system.preformComputation();
//            std::cout<< 'p'<< std::flush;
//            system.transmit();
//            std::cout<< 't'<< std::flush;
//            if(i%100 == 0){
//                double last100RoundCon = system.getGlobalLedger().size() - prvConfirmed;
//                double last100RoundSub = totalSub - prvSub;
//                double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//                double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//                double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),i-100);
//                csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//                prvConfirmed = system.getGlobalLedger().size();
//                prvSub = totalSub;
//            }
//
//        }
//        double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//        double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS - 100);
//        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//    }
//
//
//    csv << "1 every per round"<< std::endl;
//    for(int r = 0; r < NUMBER_OF_RUNS; r++){
//        bCoinReferenceCommittee system = bCoinReferenceCommittee();
//        system.setGroupSize(GROUP_SIZE);
//        system.setToRandom();
//        system.setToOne();
//        system.setLog(log);
//        system.initNetwork(PEER_COUNT);
//        system.makeByzantines(NUMBER_OF_BYZ);
//        int secLvel = system.securityLevel1();
//
//        int totalSub = 0;
//        int prvConfirmed = 0;
//        int prvSub = 0;
//        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
//            system.shuffleByzantines(NUMBER_OF_BYZ);
//            if(i%1 == 0){
//                system.makeRequest();
//                totalSub++;
//            }
//            system.receive();
//            std::cout<< 'r'<< std::flush;
//            system.preformComputation();
//            std::cout<< 'p'<< std::flush;
//            system.transmit();
//            std::cout<< 't'<< std::flush;
//            if(i%100 == 0){
//                double last100RoundCon = system.getGlobalLedger().size() - prvConfirmed;
//                double last100RoundSub = totalSub - prvSub;
//                double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//                double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//                double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),i-100);
//                csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//                prvConfirmed = system.getGlobalLedger().size();
//                prvSub = totalSub;
//            }
//
//        }
//        double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//        double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS - 100);
//        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//    }
//
//    csv << "2 every 1 round1"<< std::endl;
//    for(int r = 0; r < NUMBER_OF_RUNS; r++){
//        bCoinReferenceCommittee system = bCoinReferenceCommittee();
//        system.setGroupSize(GROUP_SIZE);
//        system.setToRandom();
//        system.setToOne();
//        system.setLog(log);
//        system.initNetwork(PEER_COUNT);
//        system.makeByzantines(NUMBER_OF_BYZ);
//        int secLvel = system.securityLevel1();
//
//        int totalSub = 0;
//        int prvConfirmed = 0;
//        int prvSub = 0;
//        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
//            system.shuffleByzantines(NUMBER_OF_BYZ);
//            if(i%1 == 0){
//                system.makeRequest();
//                totalSub++;
//                system.makeRequest();
//                totalSub++;
//            }
//            system.receive();
//            std::cout<< 'r'<< std::flush;
//            system.preformComputation();
//            std::cout<< 'p'<< std::flush;
//            system.transmit();
//            std::cout<< 't'<< std::flush;
//            if(i%100 == 0){
//                double last100RoundCon = system.getGlobalLedger().size() - prvConfirmed;
//                double last100RoundSub = totalSub - prvSub;
//                double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//                double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//                double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),i-100);
//                csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//                prvConfirmed = system.getGlobalLedger().size();
//                prvSub = totalSub;
//            }
//
//        }
//        double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//        double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS - 100);
//        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//    }
//
//    csv << "4 every 1 round1"<< std::endl;
//    for(int r = 0; r < NUMBER_OF_RUNS; r++){
//        bCoinReferenceCommittee system = bCoinReferenceCommittee();
//        system.setGroupSize(GROUP_SIZE);
//        system.setToRandom();
//        system.setToOne();
//        system.setLog(log);
//        system.initNetwork(PEER_COUNT);
//        system.makeByzantines(NUMBER_OF_BYZ);
//        int secLvel = system.securityLevel1();
//
//        int totalSub = 0;
//        int prvConfirmed = 0;
//        int prvSub = 0;
//        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
//            system.shuffleByzantines(NUMBER_OF_BYZ);
//            if(i%1 == 0){
//                system.makeRequest();
//                totalSub++;
//                system.makeRequest();
//                totalSub++;
//                system.makeRequest();
//                totalSub++;
//                system.makeRequest();
//                totalSub++;
//            }
//            system.receive();
//            std::cout<< 'r'<< std::flush;
//            system.preformComputation();
//            std::cout<< 'p'<< std::flush;
//            system.transmit();
//            std::cout<< 't'<< std::flush;
//            if(i%100 == 0){
//                double last100RoundCon = system.getGlobalLedger().size() - prvConfirmed;
//                double last100RoundSub = totalSub - prvSub;
//                double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//                double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//                double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),i-100);
//                csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//                prvConfirmed = system.getGlobalLedger().size();
//                prvSub = totalSub;
//            }
//
//        }
//        double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
//        double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS - 100);
//        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//    }
//
//    csv << "PBFT"<< std::endl;
//    csv<< "SecLvl,totalDef,totalHonest,avgWaitingTime,double(system.getGlobalLedger().size()) / totalSub"<<std::endl;
//    csv << "1 per 4 rounds"<< std::endl;
//    for(int r = 0; r < NUMBER_OF_RUNS; r++){
//        PBFTReferenceCommittee system = PBFTReferenceCommittee();
//        system.setGroupSize(GROUP_SIZE);
//        system.setToRandom();
//        system.setToOne();
//        system.setLog(log);
//        system.initNetwork(PEER_COUNT);
//        system.setFaultTolerance(FAULT);
//        system.makeByzantines(NUMBER_OF_BYZ);
//        int secLvel = system.securityLevel1();
//
//        int totalSub = 0;
//        int prvConfirmed = 0;
//        int prvSub = 0;
//        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
//            system.shuffleByzantines(NUMBER_OF_BYZ);
//            if(i%4 == 0){
//                system.makeRequest();
//                totalSub++;
//            }
//            system.receive();
//            std::cout<< 'r'<< std::flush;
//            system.preformComputation();
//            std::cout<< 'p'<< std::flush;
//            system.transmit();
//            std::cout<< 't'<< std::flush;
//            if(i%100 == 0){
//                double last100RoundCon = system.getGlobalLedger().size() - prvConfirmed;
//                double last100RoundSub = totalSub - prvSub;
//                double avgWaitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),i-100);
//                double totalDef = totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//                double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//                csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//                prvConfirmed = system.getGlobalLedger().size();
//                prvSub = totalSub;
//            }
//
//        }
//        double totalDef = totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//        double avgWaitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),NUMBER_OF_ROUNDS - 100);
//        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//    }
//
//    csv << "1 every 2 rounds"<< std::endl;
//    for(int r = 0; r < NUMBER_OF_RUNS; r++){
//        PBFTReferenceCommittee system = PBFTReferenceCommittee();
//        system.setGroupSize(GROUP_SIZE);
//        system.setToRandom();
//        system.setToOne();
//        system.setLog(log);
//        system.initNetwork(PEER_COUNT);
//        system.setFaultTolerance(FAULT);
//        system.makeByzantines(NUMBER_OF_BYZ);
//        int secLvel = system.securityLevel1();
//
//        int totalSub = 0;
//        int prvConfirmed = 0;
//        int prvSub = 0;
//        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
//            system.shuffleByzantines(NUMBER_OF_BYZ);
//            if(i%2 == 0){
//                system.makeRequest();
//                totalSub++;
//            }
//            system.receive();
//            std::cout<< 'r'<< std::flush;
//            system.preformComputation();
//            std::cout<< 'p'<< std::flush;
//            system.transmit();
//            std::cout<< 't'<< std::flush;
//            if(i%100 == 0){
//                double last100RoundCon = system.getGlobalLedger().size() - prvConfirmed;
//                double last100RoundSub = totalSub - prvSub;
//                double avgWaitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),i-100);
//                double totalDef = totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//                double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//                csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//                prvConfirmed = system.getGlobalLedger().size();
//                prvSub = totalSub;
//            }
//
//        }
//        double totalDef = totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//        double avgWaitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),NUMBER_OF_ROUNDS - 100);
//        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//    }
//
//
//    csv << "1 every round"<< std::endl;
//    for(int r = 0; r < NUMBER_OF_RUNS; r++){
//        PBFTReferenceCommittee system = PBFTReferenceCommittee();
//        system.setGroupSize(GROUP_SIZE);
//        system.setToRandom();
//        system.setToOne();
//        system.setLog(log);
//        system.initNetwork(PEER_COUNT);
//        system.setFaultTolerance(FAULT);
//        system.makeByzantines(NUMBER_OF_BYZ);
//        int secLvel = system.securityLevel1();
//
//        int totalSub = 0;
//        int prvConfirmed = 0;
//        int prvSub = 0;
//        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
//            system.shuffleByzantines(NUMBER_OF_BYZ);
//            if(i%1 == 0){
//                system.makeRequest();
//                totalSub++;
//            }
//            system.receive();
//            std::cout<< 'r'<< std::flush;
//            system.preformComputation();
//            std::cout<< 'p'<< std::flush;
//            system.transmit();
//            std::cout<< 't'<< std::flush;
//            if(i%100 == 0){
//                double last100RoundCon = system.getGlobalLedger().size() - prvConfirmed;
//                double last100RoundSub = totalSub - prvSub;
//                double avgWaitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),i-100);
//                double totalDef = totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//                double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//                csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//                prvConfirmed = system.getGlobalLedger().size();
//                prvSub = totalSub;
//            }
//
//        }
//        double totalDef = totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//        double avgWaitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),NUMBER_OF_ROUNDS - 100);
//        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//    }
//
//    csv << "2 every round"<< std::endl;
//    for(int r = 0; r < NUMBER_OF_RUNS; r++){
//        PBFTReferenceCommittee system = PBFTReferenceCommittee();
//        system.setGroupSize(GROUP_SIZE);
//        system.setToRandom();
//        system.setToOne();
//        system.setLog(log);
//        system.initNetwork(PEER_COUNT);
//        system.setFaultTolerance(FAULT);
//        system.makeByzantines(NUMBER_OF_BYZ);
//        int secLvel = system.securityLevel1();
//
//        int totalSub = 0;
//        int prvConfirmed = 0;
//        int prvSub = 0;
//        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
//            system.shuffleByzantines(NUMBER_OF_BYZ);
//            if(i%1 == 0){
//                system.makeRequest();
//                totalSub++;
//                system.makeRequest();
//                totalSub++;
//            }
//            system.receive();
//            std::cout<< 'r'<< std::flush;
//            system.preformComputation();
//            std::cout<< 'p'<< std::flush;
//            system.transmit();
//            std::cout<< 't'<< std::flush;
//            if(i%100 == 0){
//                double last100RoundCon = system.getGlobalLedger().size() - prvConfirmed;
//                double last100RoundSub = totalSub - prvSub;
//                double avgWaitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),i-100);
//                double totalDef = totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//                double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//                csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//                prvConfirmed = system.getGlobalLedger().size();
//                prvSub = totalSub;
//            }
//
//        }
//        double totalDef = totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//        double avgWaitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),NUMBER_OF_ROUNDS - 100);
//        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//    }
//
//    csv << "4 every round"<< std::endl;
//    for(int r = 0; r < NUMBER_OF_RUNS; r++){
//        PBFTReferenceCommittee system = PBFTReferenceCommittee();
//        system.setGroupSize(GROUP_SIZE);
//        system.setToRandom();
//        system.setToOne();
//        system.setLog(log);
//        system.initNetwork(PEER_COUNT);
//        system.setFaultTolerance(FAULT);
//        system.makeByzantines(NUMBER_OF_BYZ);
//        int secLvel = system.securityLevel1();
//
//        int totalSub = 0;
//        int prvConfirmed = 0;
//        int prvSub = 0;
//        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
//            system.shuffleByzantines(NUMBER_OF_BYZ);
//            if(i%1 == 0){
//                system.makeRequest();
//                totalSub++;
//                system.makeRequest();
//                totalSub++;
//                system.makeRequest();
//                totalSub++;
//                system.makeRequest();
//                totalSub++;
//            }
//            system.receive();
//            std::cout<< 'r'<< std::flush;
//            system.preformComputation();
//            std::cout<< 'p'<< std::flush;
//            system.transmit();
//            std::cout<< 't'<< std::flush;
//            if(i%100 == 0){
//                double last100RoundCon = system.getGlobalLedger().size() - prvConfirmed;
//                double last100RoundSub = totalSub - prvSub;
//                double avgWaitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),i-100);
//                double totalDef = totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//                double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//                csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//                prvConfirmed = system.getGlobalLedger().size();
//                prvSub = totalSub;
//            }
//
//        }
//        double totalDef = totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(PBFTLedgerToDag(system.getGlobalLedger()),secLvel);
//        double avgWaitingTime = waitTimeRolling(PBFTLedgerToDag(system.getGlobalLedger()),NUMBER_OF_ROUNDS - 100);
//        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
//    }

    csv << "SBFT"<< std::endl;
    csv<< "SecLvl,totalDef,totalHonest,avgWaitingTime,double(system.getGlobalLedger().size()) / totalSub"<<std::endl;
    csv << "1 per 4 rounds"<< std::endl;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(NUMBER_OF_BYZ);
        int secLvel = system.securityLevel1();

        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%4 == 0){
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
                double last100RoundCon = system.getGlobalLedger().size() - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
                double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
                double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),i-100);
                assert(avgWaitingTime >= -1);
                csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
                prvConfirmed = system.getGlobalLedger().size();
                prvSub = totalSub;
            }

        }
        double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS - 100);
        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
    }

    csv << "1 every 2 rounds"<< std::endl;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(NUMBER_OF_BYZ);
        int secLvel = system.securityLevel1();

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
                double last100RoundCon = system.getGlobalLedger().size() - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
                double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
                double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),i-100);
                csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
                prvConfirmed = system.getGlobalLedger().size();
                prvSub = totalSub;
            }

        }
        double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS - 100);
        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
    }


    csv << "1 every round"<< std::endl;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(NUMBER_OF_BYZ);
        int secLvel = system.securityLevel1();

        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%1 == 0){
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
                double last100RoundCon = system.getGlobalLedger().size() - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
                double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
                double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),i-100);
                csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
                prvConfirmed = system.getGlobalLedger().size();
                prvSub = totalSub;
            }

        }
        double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS - 100);
        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
    }

    csv << "2 every round"<< std::endl;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(NUMBER_OF_BYZ);
        int secLvel = system.securityLevel1();

        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%1 == 0){
                system.makeRequest();
                totalSub++;
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
                double last100RoundCon = system.getGlobalLedger().size() - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
                double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
                double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),i-100);
                csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
                prvConfirmed = system.getGlobalLedger().size();
                prvSub = totalSub;
            }

        }
        double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS - 100);
        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
    }
    
    csv << "4 every round"<< std::endl;
    for(int r = 0; r < NUMBER_OF_RUNS; r++){
        SBFTReferenceCommittee system = SBFTReferenceCommittee();
        system.setGroupSize(GROUP_SIZE);
        system.setToRandom();
        system.setToOne();
        system.setLog(log);
        system.initNetwork(PEER_COUNT);
        system.makeByzantines(NUMBER_OF_BYZ);
        int secLvel = system.securityLevel1();
        
        int totalSub = 0;
        int prvConfirmed = 0;
        int prvSub = 0;
        for(int i = 0; i < NUMBER_OF_ROUNDS; i++){
            system.shuffleByzantines(NUMBER_OF_BYZ);
            if(i%1 == 0){
                system.makeRequest();
                totalSub++;
                system.makeRequest();
                totalSub++;
                system.makeRequest();
                totalSub++;
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
                double last100RoundCon = system.getGlobalLedger().size() - prvConfirmed;
                double last100RoundSub = totalSub - prvSub;
                double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
                double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
                double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),i-100);
                csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
                prvConfirmed = system.getGlobalLedger().size();
                prvSub = totalSub;
            }
            
        }
        double totalDef = totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double totalHonest = system.getGlobalLedger().size() - totalNumberOfDefeatedCommittees(system.getGlobalLedger(),secLvel);
        double avgWaitingTime = waitTimeRolling(system.getGlobalLedger(),NUMBER_OF_ROUNDS - 100);
        csv<< secLvel*GROUP_SIZE<< ","<<totalDef << ","<< totalHonest<< ","<< avgWaitingTime << ","<< double(system.getGlobalLedger().size()) / totalSub<<std::endl;
    }
}
