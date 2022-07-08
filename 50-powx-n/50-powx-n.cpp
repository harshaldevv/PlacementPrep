class Solution {
public:
    double recursiveMyPow(double x, long long n){
        
        if(x == 1 || n == 0){
            return 1;
        }
        
        if( n < 0 ){
            n = -n;
            x = 1/x;
        }
        
        if(n%2 == 1){
            return x*recursiveMyPow(x, n-1);
        }
        else{
            return recursiveMyPow(x*x, n/2);
        }
    }
    
    double iterativemyPower(double x, long long n){
        if( x== 1 || n == 0){
            return 1;
        }
        
        bool isPowerNeg = false;
        if(n < 0){
            isPowerNeg = true;
            n = -n;
        }
        
        double res = 1;
        
        while(n){
            if(n%2 == 1){
                // odd
                res *= x;
                n--;
            }
            else{
                x = x*x;
                n/=2;
            }
        }
        
        if(isPowerNeg){
            return 1/res;
        }
        else{
            return res;
        }
    
        
        
        
    }
    
    
    double myPow(double x, int n) {
        
//         long long nn = (long long)n;
        
//         return recursiveMyPow(x,nn);
        
        long long nn = (long long)(n);
        return iterativemyPower(x, nn);
        
    }
};