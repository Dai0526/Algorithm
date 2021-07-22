class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> cita(citations);
        sort(cita.begin(), cita.end());
        int hIdx = 0;
        int nPaper = cita.size();
        for(int i = 0; i < nPaper; ++i){
            int nCit = cita[i];
            if(nPaper - i > nCit){
                continue;
            }
            hIdx = max(hIdx, nPaper - i);
        }
        
        return hIdx;
    }
};