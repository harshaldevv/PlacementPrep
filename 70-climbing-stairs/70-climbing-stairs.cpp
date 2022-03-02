class Solution {
public:
    int climbStairs(int n) {
        if(n==0){
            return n;
        }
        if(n==1){
            return n;
        }
        else if(n==2){
            return n;
        }
        
        int a = 1;
        int b = 2;
        int c = a + b;
        
        for(int i = 3; i <= n ;i++){
            c = a+b;
            a=b;
            b = c;
        }
        
        //int ans = climbStairs(n-1) + climbStairs(n-2);
        return c;
        
        
        
    }
};