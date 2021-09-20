#include <vector>

using namespace std;

class DisjointSetQuickUnionPathCompression{

public:
    DisjointSetQuickUnionPathCompression(int n) : m_root(n){
        for(int i = 0; i < n; ++i){
            m_root[i] = i;
        }
    }

    int find(int x){
        if(x == m_root[x]){
            return x;
        }
        return m_root[x] = find(m_root[x]);
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