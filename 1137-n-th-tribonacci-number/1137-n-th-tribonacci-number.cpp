class Solution {
public:
    int tribonacci(int n) {
        if(n== 0 || n == 1 ){
            return n;
        }
        if(n==2){
            return n-1;
        }
        
        int a = 0;
        int b = 1;
        int c = 1;
        
        int d = 2;
        
        for(int i = 2 ; i < n ; i++){
            d = a+b+c;
            a = b;
            b = c;
            c = d;
        }
        
        return d;
        
    }
};