/*
0 1 2 3 4 5 6 7
a a c e c a a a
        |      
       
a a b c
   

KMP is better idea

*/

class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.length();
                
        int r = len / 2;        
        
        int dist = len;
        while(r >= 0){
            int curr1 = isPali(s, r, r);
            
            if(curr1 != -1){
                //cout << "r = " << r << ", curr1 = " << curr1 <<endl;
                return buildPali(s, curr1);
            }
            
            
            int curr2 = isPali(s, r - 1, r);
            if(curr2 != -1){
                //cout << "r = " << r << ", curr2 = " << curr2 << endl;
                return buildPali(s, curr2);
            }
            
            --r;
        }
        
        //cout << dist << endl;
        
        return s;
        
    }
    
    string buildPali(string s, int r){
        stringstream ss;
        int l = s.length();
        int idx = l - r - 1;
        for(int i = l - 1; i > idx; --i){
            ss << s[i];
        }
        
        ss << s;
        return ss.str();
    }
    
    int isPali(const string& s, int l, int r){
        while(l >= 0){
            if(s[l] != s[r]){
                return -1;
            }
            ++r;
            --l;
        } 
        
        return s.length() - r;
    }
    
};