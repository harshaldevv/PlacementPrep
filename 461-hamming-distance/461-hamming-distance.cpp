class Solution {
public:
    int hammingDistance(int x, int y) {
        
        // same as https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
        
        // therefore using the learning from the above ques
        // basically count the number of setbits in x^y 
        
        // return __builtin_popcount(x^y); --> counting set bits in x^y USING INBUILT FUNCTION
        
        // now counting set bits without  --> using the Brian Kernighan’s Algorithm
        
        int xorr = x^y;
        int n = xorr;
        
        int ans = 0;
        
        while(n){
            ans++;
            n = (n & (n-1) );

        }
        
        return ans;
        
        
    }
};