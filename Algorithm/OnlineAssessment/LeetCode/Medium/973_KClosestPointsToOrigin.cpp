class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](vector<int>& l, vector<int>& r){
            return (l[0] * l[0] + l[1] * l[1]) < (r[1] * r[1] + r[0] * r[0]);
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        
        for(vector<int>& pt : points){
            pq.push(pt);
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<vector<int>> out;
        while(!pq.empty()){
            out.push_back(pq.top());
            pq.pop();
        }
        
        return out;
    }
};