/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/*
BFS, deal with this question level by level
https://leetcode.com/problems/nested-list-weight-sum-ii/

*/

class Solution {
    
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        queue<NestedInteger> q;
        for(NestedInteger& ni : nestedList){
            q.push(ni);
        }
        
        int prevLevel = 0;
        int depthSum = 0;
        
        while(!q.empty()){            
            int n = q.size();
            int thisLevel = 0;
            
            for(int i = 0; i < n; ++i){
                NestedInteger ni = q.front();
                q.pop();
                
                if(ni.isInteger()){
                    thisLevel += ni.getInteger();
                }else{
                    for(NestedInteger temp : ni.getList()){
                        q.push(temp);
                    }
                }
            }
            
            prevLevel += thisLevel;
            depthSum += prevLevel;
        }
        
        
        return depthSum;
    }
    
public:
    int depthSumInverse_Naive(vector<NestedInteger>& nestedList) {
        int depth = getDepth(nestedList);
        
        return getDepthSum(nestedList, depth);
        
    }
    
    int getDepthSum(vector<NestedInteger>& nestedList, int depth){
        int sum = 0;
        for(NestedInteger& ni : nestedList){
            if(ni.isInteger()){
                sum += ni.getInteger() * depth;
            }else{
                sum += getDepthSum(ni.getList(), depth - 1);
            }
        }
        
        return sum;
    }    
    
    int getDepth(vector<NestedInteger>& nestedList){
	    int depth = 0;

	    for (NestedInteger& ni : nestedList) {
	        if (!ni.isInteger()) {
		    depth = max(depth, getDepth(ni.getList()));
	        }
	    }

	    return depth + 1;
    }
};