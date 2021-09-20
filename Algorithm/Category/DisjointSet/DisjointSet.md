# Disjoint Set

Two Implementations
1. Quick Find
2. Quick Union
3. By Rank 

set of nodes graph  
(0,1) (1,2) (1,3)
(4,5) (4,6) (1,5)

```
    0          4
    |         / \
    1        5   6
   / \
  2   3
```


## Quick Find
Element of array is the root node.

Root Array:    
Array Value 0  0  1  1  4  4  4    Root Vertex  
Array Index 0  1  2  3  4  5  6    Vertex

## Quick Union
Element of array is the parent node.

Directly connect node to the root

Root Array:  
Array Value 0  0  0  0  4  4  4    Parent Vertex  
Array Index 0  1  2  3  4  5  6    Vertex

## By Rank
Quick Union based optimazation by balancing the tree

## Comparison

| |Init|Find|Union|Connected
|---|---|---|---|---|
|Quick Find| O(N) | O(1)| O(N) | O(1) |
|Quick Union| O(N) | O(H)| O(H) | O(H) | 
|By Rank| O(N) | O(logN)| O(logN) | O(logN) |

Note: N is the number of vertices in the graph. H is the height of the tree.