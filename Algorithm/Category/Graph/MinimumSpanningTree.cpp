#include <vector>
#include <iostream>
#include <iomanip>
#include <unordered_map>

using namespace std;

// graph definition
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// Weighted Graph
class WeightedGraph{

};

void PrimeAlgo(){

}

void KruskalAlgo(){

}

void UnionFindAlgo(){

}

int main(int argc, char *argv[]){

    unordered_map<int, Node*> graph;

    return 0;
}