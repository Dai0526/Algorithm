/*
https://leetcode.com/problems/meeting-rooms-ii/

two pointers method
sort start time, and sort end time
ptr_begin, ptr_end, 

        while(ptrStart < nMeeting){
            
            if(start[ptrStart] >= finish[ptrEnd]){
                // one meeting end, before new meeting start, --nRoom
                ++ptrEnd;
                --nRoom;
            }
            
            // start a new meeting
            ++ptrStart;
            ++nRoom;
            maxRoom = std::max(nRoom, maxRoom);
        }

*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        // init and get two sorted vector
        int nMeeting = intervals.size();
        
        vector<int> start(nMeeting, 0);
        vector<int> finish(nMeeting, 0);
        
        for(int i = 0; i < nMeeting; ++i){
            start[i] = intervals[i][0];
            finish[i] = intervals[i][1];
        }
        
        std::sort(start.begin(), start.end());
        std::sort(finish.begin(), finish.end());
        
        int ptrStart = 0;
        int ptrEnd = 0;
        int nRoom = 0;
        int maxRoom = 0;
        
        while(ptrStart < nMeeting){
            
            if(start[ptrStart] >= finish[ptrEnd]){
                // one meeting end, before new meeting start, --nRoom
                ++ptrEnd;
                --nRoom;
            }
            
            // start a new meeting
            ++ptrStart;
            ++nRoom;
            maxRoom = std::max(nRoom, maxRoom);
        }
        
        return maxRoom;
    }
};