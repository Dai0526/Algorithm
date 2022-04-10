﻿#include <vector>
#include <iostream>
#include <unordered_map>
#include <exception>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

/*
Data Structure for input

@pName string - process name
@tArrival int - arrival time
@vector<int> tBursts - burst times
@nCount int - program counter, index for next burst
*/
struct Process{
    string pName;
    int tArrival;
    vector<int> tBursts;
    int nCount = 0; // ++ when it is executed
    // vector<int> tIO; // not requried in this programming problem

    Process(string name, int arrivalTime, vector<int> bursts) :
        pName(name), tArrival(arrivalTime), tBursts(bursts){}

    bool hasNextBurst(){
        return tBursts.size() > nCount;
    }

    int getNextBurst(){
        if(!hasNextBurst()){
            return -1;
        }
        return tBursts[nCount];
    }
};

/*
Data Structure running execution, put in ready queue

@pName string - owner process's name
@tBurst int - burst time for this execution
@tReady int - the timestamp it got into ready queue

@tDispatched int - time it got dispatched and running
@tComplete int - complete timestamp for this execution
*/

struct RunEntity{
    string pName = "";
    int tBurst = 0;
    int tReady = 0;

    int tDispatched = 0;
    int tComplete = 0;

    RunEntity(){};

    RunEntity(string name, int tb, int tr) : pName(name), tBurst(tb), tReady(tr){}
    void setDispatchTime(int td){
        tDispatched = td;
        tComplete = tDispatched + tBurst;
    }

    int getWaitTime(){ return tDispatched - tReady; }


};

/*
Run result stat for each process

@pName string    - process name
@tArrival int    - process arrival time
@tTurnAround int - process turnaround time
@tCompletion int - process completion time
@tWaiting int    - process waiting time
*/

struct RunStat{
    string pName;
    int tArrival;
    int tTurnAround;
    int tCompletion;
    int tWaiting;

    RunStat() {}
    RunStat(string name, int arrival) : pName(name), tArrival(arrival), tTurnAround(0), tCompletion(0), tWaiting(0) {}
};

/*
SJF Schdule Algorithm

input
@procs vector<Process*> - input data, a list of process

return 
@unordered_map<string, RunStat> - key: process name, value: running result 

*/

unordered_map<string, RunStat> RunSJFSchduling(vector<Process*> procs){
    
    // prepare output
    unordered_map<string, RunStat> result;

    // sort input by arrival time
    auto compArrival = []( Process* a, const Process* b ) { return a->tArrival < b->tArrival; };
    std::sort(procs.begin(), procs.end(), compArrival);

    // create a process mapping
    unordered_map<string, Process*> records;
    queue<string> arrivalQueue;

    for(Process* p : procs){
        string procName = p->pName;
        records[procName] = p;
        arrivalQueue.push(procName);

        result[procName] = RunStat(procName, p->tArrival);
    }      

    // init a ReadyQueue
    auto compBurst = [] (const RunEntity& a, const RunEntity& b) { return a.tBurst > b.tBurst; };
    priority_queue<RunEntity, vector<RunEntity>, decltype(compBurst)> readyQueue(compBurst);  
    

    RunEntity* pRunning = nullptr;
    int tCPU = 0;
    bool isCompleted = false;

    while(!isCompleted){

        // check if there is new proc coming
        if(!arrivalQueue.empty() && records[arrivalQueue.front()]->tArrival == tCPU){
            string arrivalName = arrivalQueue.front();
            arrivalQueue.pop();

            Process* arrivalProc = records[arrivalName];
            int tBurst = arrivalProc->getNextBurst();

            RunEntity candidate(arrivalName, tBurst, tCPU);
            readyQueue.push(candidate);
        }

        // Handle current running entity which is finsih running
        if(pRunning != nullptr && pRunning->tComplete <= tCPU){
            string procName = pRunning->pName;
            Process* proc = records[procName];

            if(proc->hasNextBurst()){
                RunEntity candidate(procName, proc->getNextBurst(), tCPU);
                readyQueue.push(candidate);     
            }else{
                // if it is done, set completion time
                result[procName].tCompletion = pRunning->tComplete;
                result[procName].tTurnAround = result[procName].tCompletion - result[procName].tArrival;
            }

            // accumlate wait time
            result[procName].tWaiting += (pRunning->tDispatched - pRunning->tReady);

            delete pRunning;
            pRunning = nullptr;
        }

        // if there is still a running entity, continue(no need to check readyQueue)
        if(pRunning != nullptr){
            ++tCPU;
            continue;
        }

        // current running entity is done, dispatch next one from ReadyQueue
        if(!readyQueue.empty()){
            RunEntity re = readyQueue.top();
            readyQueue.pop();

            // increase program count once it is executed
            ++records[re.pName]->nCount;

            pRunning = new RunEntity(re.pName, re.tBurst, re.tReady);
            pRunning->setDispatchTime(tCPU);
        } 

        ++tCPU;

        // check complete status
        if(arrivalQueue.size() == 0 && pRunning == nullptr && readyQueue.size() == 0){
            isCompleted = true;
        }
    }

    if(pRunning != nullptr){
        delete pRunning;
    }

    return result;
}
/*
1. Print run info for each process.
2. Calculate average complete time, wait time, and turnaround time
*/
void ParseStat(unordered_map<string, RunStat> result){
    float totalWait = 0.0F;
    float totalTurnaround = 0.0F;
    float totalCompletion = 0.0F;

    int nProc = result.size();

    std::cout << "SJF Result" << std::endl;
    for(auto& res : result){
        std::cout << "Process - " << res.first << endl;
        std::cout << "\t\t Arrival Time " << res.second.tArrival << endl;
        std::cout << "\t\t Complete Time " << res.second.tCompletion << endl;
        std::cout << "\t\t Wait Time " << res.second.tWaiting << endl;
        std::cout << "\t\t Turnaround Time " << res.second.tTurnAround << endl;

        totalWait += res.second.tWaiting;
        totalTurnaround += res.second.tTurnAround;
        totalCompletion += res.second.tCompletion;
    }

    std::cout << "Average Result" << endl;
    std::cout << "\t\t Avg Complete Time " << totalCompletion / nProc << endl;
    std::cout << "\t\t Avg Wait Time " << totalWait / nProc << endl;
    std::cout << "\t\t Avg Turnaround Time " << totalTurnaround / nProc << endl;
}

/*
Test for single burst
*/
void Test1(){
    std::cout << "Run Test1" << endl;
    Process procA("A", 0, {7});
    Process procB("B", 2, {4});
    Process procC("C", 4, {1});
    Process procD("D", 5, {4});

    vector<Process*> procVec { &procA, &procB, &procC, &procD };

    unordered_map<string, RunStat> results = RunSJFSchduling(procVec);
    ParseStat(results);
}

/*
Test for multiple bursts
*/
void Test2(){
    std::cout << "Run Test2" << endl;
    Process procA("A", 0, {4, 4, 4});
    Process procB("B", 2, {8, 8});
    Process procC("C", 3, {2, 2});
    Process procD("D", 7, {1, 1, 1});

    vector<Process*> procVec { &procA, &procB, &procC, &procD };
    unordered_map<string, RunStat> results = RunSJFSchduling(procVec);
    ParseStat(results);
}

int main(int argc, char* argv[]){

    try{
        Test1();
        Test2();
    }catch(exception& e){
        std::cout << "exception: " << e.what() << endl;
        return 1;
    }catch(...){
        std::cout << "unknown exception." << endl;
        return 1;
    }

    return 0;
}