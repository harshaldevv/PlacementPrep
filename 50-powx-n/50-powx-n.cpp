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
            return x * myPow(x , n-1);
        }
        else{
            return myPow(x*x, n/2);
        }
    }
    
    double myPow(double x, int n) {
        long long nn = ( (long long) (n) );
        return helper(x, nn);
        
        
        
    }
};