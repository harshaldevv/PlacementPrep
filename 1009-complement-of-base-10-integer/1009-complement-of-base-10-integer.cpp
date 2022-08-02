class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
            return 1; // base case
        }
        
        // find the MSB
        int i = 31;
        while(i>=0){
            if( (n & 1<<i) != 0){
                // found first set bit aka MSB
                break;
            }
            i--;
        }
        
        for( ; i>=0 ; i--){
            n = n ^ 1<<i;
        }
        
        return n;
        // then toggle each bit from the MSB to the end (ie LSB)
    }
};