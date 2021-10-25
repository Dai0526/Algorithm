/*
https://leetcode.com/problems/interval-list-intersections/
2 pointers

get intersection by [max[i1,i2], min[j1, j2]], and move min(j1,j2)'s pointer foward

*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        
        int l1 = firstList.size();
        int l2 = secondList.size();
        
        if(l1 == 0 || l2 == 0){
            return ans;
        }
        
        int i = 0;
        int j = 0;
        
        while(i < l1 && j < l2){
            vector<int> fst = firstList[i];
            vector<int> snd = secondList[j];
            
            int lb = max(fst[0], snd[0]);
            int ub = min(fst[1], snd[1]);
            
            if(lb <= ub){
                ans.push_back({lb, ub});
            }
            
            if(fst[1] < snd[1]){
                ++i;
            }else{
                ++j;
            }

        }
        
        return ans;
    }
};