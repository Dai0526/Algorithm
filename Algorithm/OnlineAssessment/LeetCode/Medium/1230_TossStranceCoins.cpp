/*
DFS backtracking

    0,      1,       2,      3
  0 1       0        0       0
0.2 0.8     0.2
0.3 0.56    0.38
0.4 0.336   

              (previous not * current yes) + (prev yes * curr no)
lut[i][j] = lut[i - 1][j - 1] * prob[i - 1] + lut[i - 1][j] * (1 - prob[i - 1]);
         
*/

class Solution {
public:
    
    double probabilityOfHeads(vector<double>& prob, int target) {
        
        vector<vector<double>> lut(prob.size() + 1, vector<double>(target + 1, 0.0));
        lut[0][0] = 1.0;
        
        for(int i = 1; i <= prob.size(); ++i){
            lut[i][0] = lut[i - 1][0] * (1 - prob[i - 1]);
        }
        
        for(int i = 1; i <= prob.size(); ++i){
            for(int j = 1; j <= target; ++j){
               lut[i][j] = lut[i - 1][j - 1] * prob[i - 1] + lut[i - 1][j] * (1 - prob[i - 1]);
            }
        }
        
        
        return lut[prob.size()][target];
    }
    
    
    double probabilityOfHeads_slow(vector<double>& prob, int target) {
        double ans = 0.0;
        probabilty(prob, target, 0, 1.0, ans);
        return ans;
    }
    
    void probabilty(vector<double>& prob, int target, int idx, double curr, double& dProb){
     
        if(target == 0){
            for(int i = idx; i < prob.size(); ++i){
                
                if(prob[i] == 0.0){
                    continue;
                }
                curr *= (1 - prob[i]);
            }
            
            //cout << "idx = " << idx << ", curr = " << curr << endl;
            dProb += curr;
            return;
        }
        
                
        if(idx >= prob.size()){
            return; // not possible when target != 0 but idx exceeds size
        }
        
        
        for(int i = idx; i < prob.size(); ++i){
            if(prob[i] == 0.0){
                continue;
            }
            
            curr *= prob[i];
            //cout << "curr = " << curr << endl;
            target -= 1;
            probabilty(prob, target, i + 1, curr, dProb);
            curr = curr / prob[i] * (1 - prob[i]);
            target += 1;
            
        }
        
    }
    
};