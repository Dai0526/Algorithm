/*
https://leetcode.com/problems/meeting-rooms/
Sort and compare end time with next start time
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size() == 0){
            return true;    
        }
        
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){ return a[0] < b[0]; });
         
        for(int i = 0; i < intervals.size() - 1; ++i){
            // if current end later than next start, false
            if(intervals[i][1] > intervals[i + 1][0]){
                return false;
            }
        }
        
        return true;
    }
    

};