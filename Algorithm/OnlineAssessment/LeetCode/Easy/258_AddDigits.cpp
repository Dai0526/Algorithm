class Solution {
public:
    int addDigits(int num) {
      /*  
        int temp = 0;
        while(num > 0){ 
            temp += (num % 10);
            num = num / 10;

            if(num == 0 && temp > 9){
                num = temp;
                temp = 0;
            }
        }
        
        return temp;
    */
    
        if(num == 0){
            return 0;
        }
        
        if(num % 9 == 0){
            return 9;
        }
        
        return num % 9;
        
        
    }
};