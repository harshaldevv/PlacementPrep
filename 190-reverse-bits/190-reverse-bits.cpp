class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        int l = 31;
        int r = 0;
        
        while(l>r){
            bool bit1 = n & (1<<l); 
            bool bit2 = n & (1<<r);
            
            // int bit1 and int b2 --> this wont work kyuki int karke we wont get THE ith bit 
            // rather we'll got some different number 
            // humko bool hi karna hoga --> jab bhi bit chahiye do bool
            
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