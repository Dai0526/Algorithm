/*
624. Remove Substrings
https://www.lintcode.com/problem/remove-substrings/
Given a string s and a set of n substrings. You are supposed to remove every instance of those n substrings from s so that s is of the minimum length and output this minimum length.

Example 1:
Input:
"ccdaabcdbb"
["ab","cd"]
Output:
2
Explanation: 
ccdaabcdbb -> ccdacdbb -> cabb -> cb (length = 2)
Example 2:

Input:
"abcabd"
["ab","abcd"]
Output:
0
Explanation: 
abcabd -> abcd -> "" (length = 0)


BFS - 需要考虑各种可能性
不断删减，删减到底后，放入Queue, 进入下一次删减
"ccdaabcdbb"
["ab","cd"]
*/

#include <queue>
#include <set>
#include <sstream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /*
     * @param s: a string
     * @param dict: a set of n substrings
     * @return: the minimum length
     */
    int minLength(string &s, unordered_set<string> &dict) {
        
        queue<string> myQueue;
        set<string> record;
        
        record.insert(s);
        myQueue.push(s);
        
        int minSize = s.length();
        
        while(!myQueue.empty()){

            int qsize = myQueue.size();
            for(int i = 0; i < qsize; ++i){
                
                string str = myQueue.front();
                int strSize = str.length();
                myQueue.pop();

                for(const string& item : dict){
                    // try remove all possible item from str
                    int itemSize = item.length();
                    size_t idx = str.find(item);
                
                    while(idx != std::string::npos){
                        //在原string的基础上做单次的remove,这样才能遍历各种可能性
                        stringstream ss;
                        ss << str.substr(0, idx) << str.substr(idx + itemSize);
                        string newString = ss.str();
                        
                        // if it alreay in the set, means has gone trhough it, so skip
                        if(record.find(newString) == record.end()){
                            if(newString.length() < minSize){
                                minSize  = newString.length();
                            }
                    
                            myQueue.push(newString);
                            record.insert(newString);
                        }
                    
                        idx = str.find(item, idx + 1);
                    }
                
                }
            }
        }
        
        
        return minSize;
    }
};