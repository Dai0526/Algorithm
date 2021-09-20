/*
https://leetcode.com/problems/logger-rate-limiter/
1. map<string, int> 
if not in map, add it to map
if found in map, check timestamp, if valid, update timestmp ,return true
else return false

*/
#include <map>
#include <iostream>
using namespace std;

class Logger {

private:
    map<string, int> m_recs;
    int m_nExpries;
public:
    /** Initialize your data structure here. */
    Logger() {
        m_nExpries = 10; // 10s
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(m_recs.find(message) == m_recs.end()){
            m_recs[message] = timestamp;
            return true;
        }else{
            int last = m_recs[message];
            if(timestamp - last >= m_nExpries){
                m_recs[message] = timestamp;
                return true;
            }
        }
        
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */