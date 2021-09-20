/*

the max candidate is max number in array, the total sum is decreasing
as the trend.

Thus, we can sort and do a binary searc to find if sum is equal to target

Once sum is less then target, need to validate result

*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
     
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int max = arr[n - 1];

        
        int l = 0;
        int r = max;
        
        while(l + 1 < r){
            int mid = l + (r - l) / 2;            
            int temp = getSum(arr, mid); 

            if(temp > target){
                r = mid;
            }else if(temp < target){
                l = mid;
            }else{
                return mid;
            }
        }
        
        // check l and r
        int lSum = getSum(arr, l);
        int rSum = getSum(arr, r);
        
        if(abs(lSum - target) <= abs(rSum - target)){
            return l;
        }
        
        return r;  
    }
    
    int getSum(const vector<int>& vec, int val){
        int temp = 0;
        for(int i = 0; i < vec.size(); ++i){
            temp += vec[i] > val ? val : vec[i];
        }
        return temp;
    }
    
};