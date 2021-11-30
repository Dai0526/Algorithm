/*
intput 
a. 2d array m * m
b. angle in radians       

output 2d array m * m

[000
 111        
 000
]

[010
010
010]
*/

#include <vector>
#include "math.h"
using namespace std;

/*
 
[cos(theta)  -sin(theta)   [x
                            y]
sin(theta)   cos(theta)] 

(n/2, n/2)

# # #
# # #
# # #

*/
class solution{

    vector<vector<float>> rotate(const vector<vector<float>>& src, float angle){
        int n = src.size();
        vector<vector<float>> out(n, vector<float>(n, 0));
        angle = -angle;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int iRotate = i - n / 2;
                int jRotate = j - n / 2;

                int i2 = static_cast<int>(cosf(angle) * iRotate - sinf(angle) * jRotate);
                int j2 = static_cast<int>(sinf(angle) * iRotate + cosf(angle) * jRotate);

                if(i2 < 0 || i2 >= n || j2 < 0 || j2 >= n){
                    continue; // out of bound
                }

                out[i][j] = src[i2][j2];
            }
        }

        return out;
    }


};




