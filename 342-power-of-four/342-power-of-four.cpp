class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0){
            return false;
        }
        if(n == 1){
            return true;
        }
        
        while(n>1){
            if(n%4 != 0){
                cout << "n = " << n << endl;
                return false;
            }
            else{
                n/=4;
            }
        }
        
        return n==1;
        
        
        // return n%4 == 0 && isPowerOfFour(n/4);
        
    }
};