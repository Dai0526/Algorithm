/*
https://leetcode.com/problems/permutation-sequence/
看注解继续学习思路！！！！

asking for the nth, 

1. Same as all permutation problem, find all, and save in vec

2. Algorithm
Generate input array nums of numbers from 11 to NN.
Compute all factorial bases from 00 to (N - 1)!(N−1)!.
Decrease kk by 1 to make it fit into (0, N! - 1)(0,N!−1) interval.
Compute factorial representation of kk. Use factorial coefficients to construct the permutation.
Return the permutation string.


*/
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    
    string getPermutation(int n, int k) {
        vector<int> fact(n);
        vector<int> nums;
        
        fact[0] = 1;
        nums.push_back(1);
        
        for(int i = 1; i < n; ++i){
            // generate factorial system bases 0!, 1!, ..., (n - 1)!
            fact[i] = fact[i - 1] * i;
            // generate nums 1, 2, ..., n
            nums.push_back(i + 1);
        }
        // fit k in the interval 0 ... (n! - 1)
        --k;
            
        stringstream ss;
        // compute factorial representation of k
        for(int i = n - 1; i >= 0; --i){
            int idx = k / fact[i];
            k -= idx * fact[i];
            
            ss << nums[idx];
            nums.erase(nums.begin() + idx);
        }
        
        return ss.str();
        
    }
    
    string getPermutation_slow(int n, int k) {
        
        if(n == 0){
            return "";
        }
        
        if(n == 1){
            return "1";
        }
        
        vector<int> vec;
        
        for(int i = 1; i <= n; ++i){
            vec.push_back(i);
        }
        
        vector<bool> visited(n, false);
        vector<int> perm;
        vector<vector<int>> result;
           
        dfs(vec, perm, visited, result, k);
        
        return vec2Str(result[k - 1]);
    }
    
    
    void dfs(const vector<int>& vec, vector<int>& perm, vector<bool>& visited, vector<vector<int>>& out, int target){
        if(out.size() == target){
            return;
        }
        
        if(perm.size() == vec.size()){   
            out.push_back(perm);
            return;
        }
        
        if(vec.size() < perm.size()){
            return;
        }
        
        for(int i = 0; i < vec.size(); ++i){
            if(visited[i] == true){
                continue;
            }
            
            perm.push_back(vec[i]);            
            visited[i] = true;
            
            dfs(vec, perm, visited, out, target);
            
            perm.pop_back(); 
            visited[i] = false;
        }  
    }
    
    string vec2Str(const vector<int>& v){
        stringstream ss;
        for(int n : v){
            ss << n;
        }
        
        return ss.str();
    }
    
};