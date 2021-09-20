class Solution {
public:
    int hammingDistance(int x, int y) {
        int bitCount = x ^ y;
        int dist = 0;
        
        while(bitCount != 0){
            if(bitCount % 2 == 1){
                ++dist;
            }
            bitCount = bitCount >> 1;
        }
        
        return dist;
    }
};