#include <vector>
using namespace std;

class UnionFind {
public:
    UnionFind(int n) : m_root(n), m_rank(n) {
        for (int i = 0; i < n; ++i) {
            m_root[i] = i;
            m_rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == m_root[x]) {
            return x;
        }
        return m_root[x] = find(m_root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (m_rank[rootX] > m_rank[rootY]) {
                m_root[rootY] = rootX;
            } else if (m_rank[rootX] < m_rank[rootY]) {
                m_root[rootX] = rootY;
            } else {
                m_root[rootY] = rootX;
                m_rank[rootX] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> m_root;
    vector<int> m_rank;
};
