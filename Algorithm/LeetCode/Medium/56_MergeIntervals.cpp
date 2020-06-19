/*
https://leetcode.com/problems/merge-intervals/
QFA: Sorted by first bracket?

After Sort -> [[1,3],[2,6],[8,10],[15,18]]

compare left and right

push to result when    right < new left
otherwise, update left and right for range of intervals.

*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        
        int nSize = intervals.size();
        
        if(nSize == 0){
            return vector<vector<int>>();
        }
        
        // sort by start value
        sort(intervals.begin(), intervals.end(), [](vector<int>& inv1, vector<int>& inv2){return (inv1[0] - inv2[0]) < 0;});
        
        // push first pair to result
        vector<vector<int>> res;
        
        int l = intervals[0][0];
        int r = intervals[0][1];
        
        for(int i = 0; i < nSize; ++i){
            int front = intervals[i][0];
            int back = intervals[i][1];
            
            // no overlap
            if(r < front){
                res.push_back({l, r});
                l = front;
                r = back;
            }else{
                r = r < back ? back : r;
            }
        }
        res.push_back({l,r});
        return res;
    }
};