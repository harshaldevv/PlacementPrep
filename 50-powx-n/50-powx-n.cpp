class Solution {
public:
    
    double helper(double x, long long n){
        if(n == 0 || x == 1){
            return 1;
        }
        
        if(n < 0 ){
            n = n*(-1);
            x = 1/x;
        }
        
        if(n%2 == 1){
            // n == odd
            // return x * myPow(x , n-1);
            return x * myPow(x*x , n/2);
        }
        else{
            return myPow(x*x, n/2);
        }
    }
    
    double iterativeMyPow(double x, long long n){
    
        if(x == 1 || n ==0){
            return 1;
        }
        
        bool isNeg = false; 
        // isNeg stores if the power was negative. If it was negative
        // then we need to just 1/res our final answer
        
        if(n < 0){
            isNeg = true;
            n = -n;
        }
        
        double res = 1;
        
        while(n){
            if(n%2 == 1){
                res*= x;
                n--;
            }
            else{
                x = (x*x);
                n/=2;
            }
        }
        
        if(isNeg){
            res = 1/res;
        }
        
        return res;
    }
    
    double myPow(double x, int n) {
        // long long nn = ( (long long) (n) );
        // return helper(x, nn);
        
        long long nn = (long long)(n);
        return iterativeMyPow(x, nn);
        
        
        
    }
};