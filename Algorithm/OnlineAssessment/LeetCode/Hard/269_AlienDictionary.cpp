/*
1. build directional graph
2. topological sort


*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <sstream>

using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        
        // build graph
        unordered_map<char, unordered_set<char>> graph;
        if(!buildGraph(graph, words)){
            return "";
        }
        
        // topological sort
        return topoSort(graph);
    }
    
    bool buildGraph(unordered_map<char, unordered_set<char>>& graph, const vector<string>& words){
        // build graph
        for(string s : words){
            for(char c : s){
                if(graph.find(c) == graph.end()){
                    graph[c] = unordered_set<char>();
                }
            }
        }
        
        for(int i = 0; i < words.size() - 1; ++i){
            
            
            if(words[i].size() > words[i + 1].size() && isPrefix(words[i], words[i + 1])){
                cout << "fst = " << words[i] << ", snd " << words[i + 1] << endl;
                return false; // invalid
            }
            
            int len = min(words[i].length(), words[i + 1].length());
            int j = 0;
            for(; j < len; ++j){
                if(words[i][j] != words[i + 1][j]){
                    graph[words[i][j]].insert(words[i + 1][j]);
                    break;
                }
            }
        }
        
        return true;
    }
    
    bool isPrefix(const string& fst, const string& snd){
        if(fst.rfind(snd, 0) == 0){
            return true;
        }
        return false;
    }
    
    string topoSort(unordered_map<char, unordered_set<char>>& graph){
        unordered_map<char, int> degree;
        queue<char> q;
        
        stringstream ss;
        
        for(auto pair : graph){
            //char c = pair.first;
            for(char c : pair.second){
                ++degree[c];
            }
        }
        
        for(auto pair : graph){
            char c = pair.first;
            if(degree[c] == 0){
                q.push(c); // add 0 degree item to queue
            }
        }
        
        // bfs
        while(!q.empty()){
            char curr = q.front();
            q.pop();
            ss << curr;
            
            for(char nb : graph[curr]){
                --degree[nb];
                if(degree[nb] == 0){
                    q.push(nb);
                }
            }
        }
        
        
        string str = ss.str();
        if(str.size() < graph.size()){
            return "";
        }
        
        return str;
    }
    
};