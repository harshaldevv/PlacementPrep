class Solution {
public:
    int findComplement(int num) {
        // TC - O(N), SC - O(1)
        
        // basically toggle every bit
        // therefore do n ^ 1<<i
        
        int n = num;
        
        // now we gotta find the MSB first
        int i = 31;
        
       while(i>=0){
           if( ( n & (1<<i) ) != 0 ){
               // found MSB (set bit)
               break;
           }
           i--;
       }
        
        // now toggle each bit from this i onwards
        for( ; i >=0 ; i--){
            n = n ^ 1<<i;
        }
        
        return n;
        
    }
};