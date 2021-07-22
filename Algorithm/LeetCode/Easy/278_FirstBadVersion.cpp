// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

/*
https://leetcode.com/problems/first-bad-version/
*/

class Solution {
public:
    int firstBadVersion(int n) {
        // binary search  
        int head = 1;
        int tail = n;
           
        while(head < tail - 1){       
            int mid = (tail - head) / 2 + head;
            if(isBadVersion(mid)){
                tail = mid;
            }else{
                head = mid;
            }
        }
        
        if(isBadVersion(head)){
            return head;
        }
        
        return tail;     
    }
};