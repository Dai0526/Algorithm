
/*
Union Find

*/

#include <vector>
using namespace std;

class UnionFind{

public:
    UnionFind(int n): parents(n){
        for(int i = 0; i < n; ++i){
            parents[i] = i;
        }
    }
    
    
    int find(int x){
        while(parents[x] != x){
            x = parents[x];
        }
        return x;
    }
    
    
    bool unionSet(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        //cout << "x = " << x <<", rootX = " << rootX << endl;
        //cout << "y = " << y <<", rootY = " << rootY << endl;
        if(rootX == rootY){
            return false;
        }
        
        parents[rootX] = rootY; // already unioned
        return true;
    }
    
private:
    
    vector<int> parents;
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // edge.size == n - 1
        if(edges.size() != n - 1){
            return false;
        }
        
        // union find
        UnionFind uf(n);
        
        for(vector<int>& e : edges){
            int A = e[0];
            int B = e[1];
            
            if(!uf.unionSet(A, B)){
                //cout <<"at A = " << A << ", B = " << B << " is false" << endl;
                return false;
            }   
        }
        
        return true;
    }
};

