// better to define comparator and hash for struct, then directly use it in map
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    
    struct Point{
        int x;
        int y;
        
        Point(int a, int b){
            x = a;
            y = b;
        }
        
        bool operator==(const Point & other) const{
            return (x == other.x && y == other.y);
        }
        
        
    };
    
    // y = ax + b
    struct Line{
        double a = 0.0;
        double b = 0.0;
        
        bool operator==(const Line & other) const{
            return (a == other.a && b == other.b);
        }
        
        Line(int x1, int y1, int x2, int y2){
            if(x1 - x2 == 0){
                a = x1 * 1E9;
            }else{
                a = (y1 - y2) / ((float)(x1 - x2));
            }
            
            b = y1 - a * x1;
        }
        
        Line(const Point& p1, const Point& p2){
            if(p1.x - p2.x == 0){
                a = p1.x * 1E9;
            }else{
                a = (p1.y - p2.y) / ((float)(p1.x - p2.x));
            }
            
            b = p1.y - a * p1.x;
        }
        
    };
    

    
    int maxPoints(vector<vector<int>>& points) {
        int l = points.size();
        
        // 0 points return 0, 1 point return 1, 2 poingt return 2
        if(l <= 2){
            return l;
        }
        
        map<float, map<float, set<pair<int, int>>>> cnt;
        
        int res = numeric_limits<int>::min();
        
        for(int i = 0; i < l; ++i){
            for(int j = i + 1; j < l; ++j){
                
                Point pt1(points[i][0], points[i][1]);
                Point pt2(points[j][0], points[j][1]);
                
                Line temp(pt1, pt2);
                
                cnt[temp.a][temp.b].insert({pt1.x, pt1.y});
                cnt[temp.a][temp.b].insert({pt2.x, pt2.y});

                res = max(res, (int)cnt[temp.a][temp.b].size()); 
            }
        }
        
        return res;
    }
};