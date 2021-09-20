
/*
601. Flatten 2D Vector
https://www.lintcode.com/problem/flatten-2d-vector/
Implement an iterator to flatten a 2d vector.

Example
Example 1:

Input:[[1,2],[3],[4,5,6]]
Output:[1,2,3,4,5,6]
Example 2:

Input:[[7,9],[5]]
Output:[7,9,5]


use x,y for row and col

1. for next()
check hasNext(), if has, return (x, ++y)

2. has next,
if y == vec[x].size(), then ++x, y = 0
if(x < vec2d.size())
return false;

The problem is that I have to copy vector, which waste space, use a pointer 
Since it is in C++, use std::iterator for it.


*/

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        
        current = vec2d.begin();
        end = vec2d.end();
        
        idx = 0;
    }

    int next() {
        hasNext();
        
        return (*current)[idx++];
        
    }

    bool hasNext() {
        
        // list can be emptyl, so use while instead of
        while(current != end && idx == (*current).size()){
            // set current to next row, idx to first element
            ++current;
            idx = 0;
        }
        
        return current != end;
    }
    
private:

    vector<vector<int>>::iterator current, end;
    int idx;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */