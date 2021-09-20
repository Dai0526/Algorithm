/*
https://leetcode.com/problems/subarray-sum-equals-k/solution/


QFA:
Sorted?
has negative number?


IDEA:

two pointers, slide window


*/
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int subarraySum_slow(vector<int>& nums, int k) {
        
        int nSize = nums.size();
        
        int count = 0;
        
        for(int i = 0; i < nSize; ++i){
            int sum = 0;
            
            for(int j = i; j < nSize; ++j){
                sum += nums[j];
                if(sum == k){
                    ++count;
                }
            }    
        }
        
        return count;
    }
    
    /*
    The idea behind this approach is as follows: 
    If the cumulative sum(repreesnted by sum[i]sum[i] for sum upto i^{th} ith index) upto two 
    indices is the same, the sum of the elements lying in between those indices is zero. 
    Extending the same thought further, if the cumulative sum upto two indices, 
    say ii and jj is at a difference of kk i.e. if sum[i] - sum[j] = ksum[i]−sum[j]=k, the sum of elements lying between indices ii and jj is kk.

    Based on these thoughts, we make use of a hashmap mapmap which is used to store the cumulative 
    sum upto all the indices possible along with the number of times the same sum occurs. 
    We store the data in the form: (sum_i, no. of occurences of sum_i)(sum i, no.ofoccurencesofsum i). We traverse over the array numsnums and keep on finding the cumulative sum. Every time we encounter a new sum, we make a new entry in the hashmap corresponding to that sum. If the same sum occurs again, we increment the count corresponding to that sum in the hashmap. Further, for every sum encountered, we also determine the number of times the sum sum-ksum−k has occured already, since it will determine the number of times a subarray with sum kk has occured upto the current index. We increment the countcount by the same amount.
    
    */

    int subarraySum(vector<int>& nums, int k) {
        
        map<int, int> rec; // key is accumlate sum, int is # of occur
        rec[0] = 1; // init 
        
        int sum = 0;
        int count = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            
            int diff = sum - k;
            
            if(rec.find(diff) != rec.end()){
                count += rec[diff];
            }
            
            rec[sum] = rec[sum] + 1;
        }
        
        return count;
    }
    
    
};