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
            m_logfs.open(m_fullPath);
        }

        ~MyLog(){
            m_logfs.close();
        }

        template<typename T> 
        MyLog& operator<< (const T& data) 
        {
            m_logfs << data;
            cout << data;
            return *this;
        }

    private:
        string m_fullPath = "";
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
    
    MyLog logging(".//BankerAlgoLog.txt");
    logging << "Start Test" << endl;
    logging << "Available Resource: " << getVecStr(avil);
    logging << "Total Resource: " << getVecStr(total);
    logging << "Current Resource: " << getMatStr(curr);
    logging << "Required Resource: " << getMatStr(maxReq);
    
    int nProc = maxReq.size();        // proc count
    int nResource = maxReq[0].size(); // resource count

    queue<int> pids; 
    for(int p = 0; p < nProc; ++p){
        pids.push(p);
    }

    bool isSafe = true;
    int nRound = 1;
    while(!pids.empty()){
        //cout << "Round - " << nRound << endl;
        logging << "Round - " << nRound;

        int qSize = pids.size();
        for(int i = 0; i < qSize; ++i){
            // pop one client from queue to check
            int currPid = pids.front();
            pids.pop();
            //cout << "\tCheck Client # " << currPid << endl;
            logging << "\tCheck Client # " << currPid;

            int* pCurrProcRes = curr[currPid].data(); // use ptr to avoid making copy of vec
            int* pCurrProcMax = maxReq[currPid].data();

            // start check each resources for this client
            bool isSafe = true;
            for(int r = 0; r < nResource; ++r){
                int resGap = pCurrProcMax[r] - pCurrProcRes[r];

                if(resGap <= 0){
                    //cout << "\t\tAlready has enough RS" << r << ", no request" << endl;
                    logging << "\t\tAlready has enough RS" << r << ", no request";
                    continue;
                }

                //cout << "\t\tRequesting " << resGap << " unit(s) of RS" << r << endl;
                logging << "\t\tRequesting " << resGap << " unit(s) of RS" << r;
                if(resGap > avil[r]){
                    // report unsafe
                    //cout << "\t\t\t[Failed] not enough available resource RS" << r << endl;
                    logging << "\t\t\t[Failed] not enough available resource RS" << r;
                    
                    // add proc back to queue for next rounds check
                    isSafe = false;
                    break;
                }
                //cout << "\t\t\t[Success]" << endl;
                logging << "\t\t\t[Success]";
            }

            if(!isSafe){
                pids.push(currPid);
                //cout << "\t\tPush back Client #" << currPid << " for next round"<< endl;
                logging << "\t\tPush back Client #" << currPid << " for next round";
            }else{
                // release the resource that curr Pid owned
                for(int r = 0; r < nResource; ++r){
                    avil[r] += pCurrProcRes[r];
                }
                --nProc;  // reduce current process count
                //cout << "\t\tClient " << currPid << " finished and released his resources." << endl;
                logging << "\t\tClient " << currPid << " finished and released his resources.";
            } // if - check safe
        }

        ++nRound;
        // check if it makes any progress
        //cout << "\tInitial Clients number = " << qSize << ", Remainning Clients = " << nProc << endl;
        logging << "\tInitial Clients number = " << qSize << ", Remainning Clients = " << nProc;
        if(qSize == nProc){
            //cout << "\tNo progress was made(Deadlock happends). In a UNSAFE state.\r\n" << endl;
            logging << "\tNo progress was made(Deadlock happends). In a UNSAFE state.\r\n";
            isSafe = false;
            break; //break while check
        }

        //cout << "\t" << qSize - nProc << " Clients got the resource and Released. SAFE for now.\r\n" << endl;
        logging << "\t" << qSize - nProc << " Clients got the resource and Released. SAFE for now.\r\n";

    }

    //check result
    if(isSafe){
        //cout << "[SAFE] - The initial state is safe to release all clients." << endl;
        logging << "[SAFE] - The initial state is safe to release all clients.";
    }else{
        //cout << "[UNSAFE] - The initial state is unsafe, and the following Clients are blocked:" << endl;
        logging << "[UNSAFE] - The initial state is unsafe, and the following Clients are blocked:";
        int nRemain = pids.size();
        for(int i = 0; i < nRemain; ++i){
            int clnt = pids.front();
            pids.pop();
            //cout << "\tClient #" << clnt << endl; 
            logging << "\tClient #" << clnt; 
        }
    }

    return isSafe;
}




int test(){
    
    // Use Assignment 3 - Ques 2 as a test case
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