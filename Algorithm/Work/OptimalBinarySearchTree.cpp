#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
void printTable(const vector<vector<T>>& src, const string& title){
    int r = src.size();
    int c = src[0].size();

    cout << title << " [" << r << " * " << c << "]: " << endl; 

    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            cout << setw(6) << src[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\r\n"; 
};

void OptimalBST(const vector<int> &nodes, const vector<float> &p, const vector<float> &q,
                vector<vector<float>>& costs, vector<vector<float>>& probs, vector<vector<int>>& roots)
{

    int n = nodes.size();
    costs.resize(n + 1, vector<float>(n + 1));  //e
    roots.resize(n, vector<int>(n));            // roots
    probs.resize(n + 1, vector<float>(n + 1));  //w

    // init table
    int len = n + 1;
    for(int i = 0; i < len; ++i){
        costs[i][i] = q[i];
        probs[i][i] = q[i];
    }

    for(int l = 1; l <= n; ++l){
        for(int i = 0; i < n - l + 1; ++i){
            int j = i + l;
            costs[i][j] = numeric_limits<float>::max();
            probs[i][j] = probs[i][j - 1] + p[j - 1] + q[j];
            for(int r = i; r < j; ++r){
                float temp = costs[i][r] + costs[r + 1][j] + probs[i][j];
                if(temp < costs[i][j]){
                    costs[i][j] = temp;
                    roots[i][j - 1] = nodes[r];
                }
            }
        }
    }
};

/*
Let table row be i and column be j, the each cell means the optimal root for subproblem [i, j].
Thus, we can recursively construct the binary search tree. For example:
1. [0, 1, 2, 3, 4, ... , n]  
    r1 = table[0][n]
2. [0, 1, 2, ... r1 - 1] [r1] [r1 + 1, r1 + 2, ... n]
    Two 

*/

void recoverTree(const vector<vector<int>>& roots){
    int n = roots.size();
    

}

void recoverTreeRec(const vector<vector<int>>& roots, int l, int r, int parent, bool isLeft){

    string branch = isLeft ? "left" : "right";

    if(l > r){
        // is a dummy node
        int dummyCount = isLeft ? parent - 1 : parent;
        cout << "d" << dummyCount << " is the " << branch << " of k" << parent << endl;
        return;
    }

    // get the optimal root for the sub-problem
    int key = roots[l][r];
    int keyIdx = key - 1;

    
    if(l == 0 && r == roots.size() - 1){
        // case 1, root
        cout << "k" << key << " is the root" << endl;
    }else{
        // case 2, child
        cout << "k" << key << " is the " << branch << " child of " << "k" << parent << endl;
    }

    // find left
    recoverTreeRec(roots, l, keyIdx - 1, key, true);
    recoverTreeRec(roots, keyIdx + 1, r, key, false);
}

int main(int argc, char *argv[]){

    vector<float> p { 0.15F, 0.10F, 0.05F, 0.10F, 0.20F };  
    vector<float> q { 0.05F, 0.10F, 0.05F, 0.05F, 0.05F, 0.10F };
    
    vector<int> keys { 1, 2, 3, 4, 5};

    vector<vector<float>> probs;
    vector<vector<float>> costs;
    vector<vector<int>> roots;

    OptimalBST(keys, p, q, costs, probs, roots);

    // printTable(probs, "probs table");
    // printTable(costs, "cost table");
    printTable(roots, "root table");

    // Recover the tree
    recoverTreeRec(roots, 0, 4, -1, true);

    return 0;
}