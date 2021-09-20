#include <vector>

using namespace std;

class DisjointSetQuickUnion{

public:
    DisjointSetQuickUnion(int n) : m_root(n){
        for(int i = 0; i < n; ++i){
            m_root[i] = i;
        }
    }

    int find(int x){
        while(x != m_root[x]){
            x = m_root[x];
        }
        return x;
    }

    void unionSet(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            m_root[rootY] = rootX; // already unioned
        }
    }

    bool connected(int x, int y){
        return find(x) == find(y);
    }

private:
    vector<int> m_root;

};