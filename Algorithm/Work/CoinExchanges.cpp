#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

int coinExchange(const vector<int>& coins, int val){
    int n = coins.size();
    vector<int> lut(val + 1, 0);

    for(int i = 1; i <= val; ++i){
        int minCount = numeric_limits<int>::max();
        for(int j = 0; j < n; ++j){
            if(i >= coins[j]){
                minCount = min(minCount, 1 + lut[i - coins[j]]);
                cout << "i = " << i << ", j = " << j << ", min = " << minCount << endl;
                lut[i] = minCount;
            }
        }   
    }

    return lut[val];
}


int main(int argc, char *argv[]){
    
    int value = 24;
    vector<int> coins { 1, 5, 8, 15, 20};

    cout << "ans is " << coinExchange(coins, value) << endl;

    return 0;
}