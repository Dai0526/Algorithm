#include <vector>

using namespace std;

class DisjointSetQuickFind{

public:
    DisjointSetQuickFind(int n) : m_root(n){
        for(int i = 0; i < n; ++i){
            m_root[i] = i;
        }
    }

    int find(int x){
        return m_root[x];
    }

    void unionSet(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return; // already unioned
        }

        for (int i = 0; i < m_root.size(); ++i) {
            if (m_root[i] == rootY) {
                m_root[i] = rootX;
            }
        } 
    }


    bool connected(int x, int y){
        return find(x) == find(y);
    }

private:
    vector<int> m_root;

};