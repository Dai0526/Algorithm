class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        
        // binary search to find the closest item
        int l = 0;
        int r = arr.size() - 1;
        
        while(l + 1 < r){
            int mid = l + (r - l) / 2;
            if(arr[mid] > x){
                r = mid;
            }else{
                l = mid;
            }
        }
        
        vector<int> ans;
        int idx = getCloser(l, r, x, arr);
        //cout <<idx<<endl;
        ans.push_back(arr[idx]);
        --k;
 
        l = idx - 1;
        r = idx + 1;
        // two pointers
        while(k > 0 && l >= 0 && r < arr.size()){
            int temp = getCloser(l, r, x, arr);
            
            if(temp == l){
                --l;
            }else{
                ++r;
            }
            
            ans.push_back(arr[temp]);
            --k;  
        }
        
        // right to the end
        while(k > 0 && l >= 0){
            ans.push_back(arr[l]);
            
            --k;
            --l;
        }
        
        while(k > 0 && r < arr.size()){
            ans.push_back(arr[r]);
            --k;
            ++r;
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    int getCloser(int a, int b, int x, const vector<int>& arr){
        int diffA = abs(arr[a] - x);
        int diffB = abs(arr[b] - x);
        
        
        if(diffA < diffB || (diffA == diffB && a < b)){
            return a;
        }
        
        return b;
    }
    
};