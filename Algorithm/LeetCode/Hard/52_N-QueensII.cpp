class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>> res;
        vector<int> queens;
        
        dfs(n, queens, res);
        
        return res.size();        
    }
    
    void dfs(int n, vector<int>& queens, vector<vector<string>>& out){
        if(n == queens.size()){
            out.push_back(makeBoard(queens));
            return;
        }
        
        int row = queens.size();
        
        for(int col = 0; col < n; ++col){
            if(!isValid(col, row, queens)){
                continue;
            }
            
            queens.push_back(col);
            dfs(n, queens, out);
            queens.pop_back();
            
        }   
    }
    
    bool isValid(int col, int row, const vector<int>& queens){
        for(int i = 0; i < queens.size(); ++i){
            int j = queens[i];
            if(col == j || row == i || abs(j - col) == abs(i - row)){
                return false;
            }
        }
         
        return true;
    }
    
    vector<string> makeBoard(const vector<int>& queens){
        vector<string> bd;
        int nq = queens.size();
        for(int i = 0; i < nq; ++i){
            string temp = "";
            int col = queens[i];
            for(int j = 0; j < nq; ++j){
                if(j == col){
                    temp += "Q";
                }else{
                    temp += ".";
                }
            }
            bd.push_back(temp);
        }
        
        return bd;
    }
};