class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        int l = 31;
        int r = 0;
        
        while(l>r){
            bool bit1 = n & (1<<l);
            bool bit2 = n & (1<<r);
            
            if(bit1 != bit2){
                //toggle the bits
                n = n^(1<<l);
                n = n^(1<<r);
            }
            
            l--;  //-> hum usually l++ and r-- karte hai, but mene l-- and r++ kia hai
            r++;
        }
        
        return n;
        
    }
};