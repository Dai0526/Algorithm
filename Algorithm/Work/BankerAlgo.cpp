#include <exception>
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <fstream>

using namespace std;

/*
Helper Functions
    1. printIntVec
    2. printIntMat
*/
string getVecStr(const vector<int>& vec){
    stringstream ss;
    ss << "[";
    for(int n : vec){
        ss << n << " ";
    }
    ss << "]" << endl;
    return ss.str();
}

string getMatStr(const vector<vector<int>>& mat){
    stringstream ss; 
    int r = mat.size();
    int c = mat[0].size();
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            ss << mat[i][j] << " ";
        }
        ss << endl;
    }

    return ss.str();
}
// a simple log class to print log and save log to file after program finished
class MyLog{
    public:
        MyLog(const string& fullpath): m_fullPath(fullpath) {
            m_logfs.open(fullpath);
        }

        ~MyLog(){
            m_logfs.close();
        }

        void Write(const string& s){
            cout << s << endl;
            m_logfs << s << endl;
        }    

    private:
        string m_fullPath;
        ofstream m_logfs;
};

/*
    *Assume the dimensions are valid and no need to check, e.g. avil.size() = existResource.size, etc    

    The idea is using breadth first search, check one by one. 
        Within a single check round, 
            if no progress made in terms of no process can be released, it is a deadlock
        In the end, if queue becomes empty, means all process can be released, it is safe.
*/
bool Bankers(vector<int> avil, vector<int> total, vector<vector<int>> curr, vector<vector<int>> maxReq){
    // start logging and log input data
    MyLog logger(".//BankerAlgoLog.txt");
    logger.Write("Start Test");
    logger.Write("Available Resource: " + getVecStr(avil));
    logger.Write("Total Resource: " + getVecStr(total));
    logger.Write("Current Resource: " + getMatStr(curr));
    logger.Write("Required Resource: " + getMatStr(maxReq));
    
    int nProc = maxReq.size();        // proc count - to check progress
    int nResource = maxReq[0].size(); // resource count

    queue<int> pids;  // a client queue to check
    for(int p = 0; p < nProc; ++p){
        pids.push(p);
    }

    bool isSafe = true;
    int nRound = 1;

    // use BFS method to check each client
    while(!pids.empty()){
        logger.Write("Round - " + to_string(nRound));

        int qSize = pids.size();
        for(int i = 0; i < qSize; ++i){
            // pop one client from queue to check
            int currPid = pids.front();
            pids.pop();

            logger.Write("\tCheck Client #" + to_string(currPid));

            // use ptr to avoid making copy of vec
            int* pCurrProcRes = curr[currPid].data(); 
            int* pCurrProcMax = maxReq[currPid].data();

            // start check each resources for this client
            bool isSafe = true;
            for(int r = 0; r < nResource; ++r){
                int resGap = pCurrProcMax[r] - pCurrProcRes[r];

                if(resGap <= 0){
                    logger.Write("\t\tAlready has enough RS" + to_string(r) + ", no request");
                    continue;
                }

                logger.Write("\t\tRequesting " + to_string(resGap) + " unit(s) of RS" + to_string(r));
                if(resGap > avil[r]){
                    // report unsafe
                    logger.Write("\t\t\t[Failed] not enough available resource RS" + to_string(r));
                    isSafe = false;
                    break;
                }
            }

            // process result
            if(!isSafe){
                // if unsafe, then push back current client
                pids.push(currPid);
                logger.Write("\t\tPush back Client #" + to_string(currPid) + " for next round");
            }else{
                // if safe, release the resource that curr Pid owned, and decrease client count
                for(int r = 0; r < nResource; ++r){
                    avil[r] += pCurrProcRes[r];
                }
                --nProc;  // reduce current process count

                logger.Write("\t\t\t[Success]");
                logger.Write("\t\tClient " + to_string(currPid) + " finished and released his resources.");
            }
        }

        ++nRound;

        // check if it makes any progress
        logger.Write("\tInitial Clients number = " + to_string(qSize) + ", Remainning Clients = " + to_string(nProc));
        
        if(qSize == nProc){
            logger.Write("\tNo progress was made(Deadlock happends). In a UNSAFE state.\r\n");
            isSafe = false;
            break; //break while check
        }

        logger.Write("\t" + to_string(qSize - nProc) + " Clients got the resource and Released. SAFE for now.\r\n");
    }

    //check result
    if(isSafe){
        logger.Write("[SAFE] - The initial state is safe to release all clients.");
    }else{
        logger.Write("[UNSAFE] - The initial state is unsafe, and the following Clients are blocked:");
        int nRemain = pids.size();
        for(int i = 0; i < nRemain; ++i){
            int clnt = pids.front();
            pids.pop();
            logger.Write("\tClient #" + to_string(clnt)); 
        }
    }

    return isSafe;
}

// Use Assignment 3 - Ques 2 as a test case
int test(){

    vector<int> avilResource = { 0, 1, 0, 2, 1 };   // [0, 1, 0, 2, 1]
    vector<int> existResource = { 2, 4, 1, 4, 4 };  // [2, 4, 1, 4, 4]

    vector<vector<int>> maxRequest;
    maxRequest.push_back({1, 1, 0, 2, 1});
    maxRequest.push_back({0, 1, 0, 2, 1});
    maxRequest.push_back({0, 2, 0, 3, 1});
    maxRequest.push_back({0, 2, 1, 1, 0});
    
    vector<vector<int>> currAllocation;
    currAllocation.push_back({0, 1, 1, 1, 2});
    currAllocation.push_back({0, 1, 0, 1, 0});
    currAllocation.push_back({0, 0, 0, 0, 1});
    currAllocation.push_back({2, 1, 0, 0, 0});

    Bankers(avilResource, existResource, currAllocation, maxRequest);

    return 0;
}

int main(){
    
    try{
        test();
    }catch(exception & ex){
        cerr << ex.what() << endl;
        return 1;
    }catch(...){
        cerr << "Unknow exception" << endl;
        return 1;
    }

    return 0;
}