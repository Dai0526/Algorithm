/*
128. Hash Function
中文English
In data structure Hash, hash function is used to convert a string(or any other type) into an integer smaller 
than hash size and bigger or equal to zero. The objective of designing a hash function is 
to "hash" the key as unreasonable as possible. A good hash function can avoid collision as less as possible. 
A widely used hash function algorithm is using a magic number 33, consider any string as a 33 based 
big integer like follow:

hashcode("abcd") = (ascii(a) * 333 + ascii(b) * 332 + ascii(c) *33 + ascii(d)) % HASH_SIZE 
                              = (97* 333 + 98 * 332 + 99 * 33 +100) % HASH_SIZE
                              = 3595978 % HASH_SIZE
here HASH_SIZE is the capacity of the hash table (you can assume a hash table is like an array with index 0 ~ HASH_SIZE-1).
Given a string as a key and the size of hash table, return the hash value of this key.

Example 1:
Input:  key="abcd", size = 1000
Output: 978
Explanation: (97*33^3 + 98*33^2 + 99*33 + 100*1)%1000 = 978

Example 2:
Input:  key="abcd", size = 100
Output: 78
Explanation: (97*33^3 + 98*33^2 + 99*33 + 100*1)%100 = 78
Clarification
For this problem, you are not necessary to design your own hash algorithm or consider any collision issue, you just need to implement the algorithm as described.


公式很简单，关键在于考虑是否值过大导致溢出

1. 首先用long long给予最大限度的空间
2. 优化函数
第一步优化
result += key[i] * pow(33, l - 1 - i) % hashCode
但是pow 那一步依然会过大，所以继续优化
result = (key[i] + result * 33) % hashCode 
===> 第一次的key会被乘上 （l-1) 次的33， 这样就避免了一次因为pow（）导致的值过大
*/


#include <iostream>

using namespace std;
class Solution {
public:
    /**
     * @param key: A string you should hash
     * @param HASH_SIZE: An integer
     * @return: An integer
     */
    int hashCode(string &key, int HASH_SIZE) {
        
        long long hash = 0;
        int l = key.length();
        const int BASE = 33;
        
        for(int i = 0; i < l; ++i){
            // hash function can be simplified to result = (result * 33 + key) % hash_code
            hash = (key[i] + hash * 33) % HASH_SIZE;
        }
        
        return hash;
    }
};