class Solution {
public:
    bool isPowerOfFour(int n) {
        // TC - O(32)   --> as we traverse max of 32 bits ---> = O(1) 
        // SC - O(1)
        /// check if n is a power of 2 or not
        if(n<0){
            return false; // --> negative numbers toh power of 4 ho hi nahi sakte -
            // eg n = -4 cant be acheived by taking any power of 4 (ie 4^x) 
        }
        
        if( (n & (n-1) ) != 0){
            return false; // the number is not a power of 2 , therefore it can be a power of 4
        }
        // now that we know it is a power of 2 --> therefore it contains only one set bit
        // and if a number is a power of 4, its set bit would exist at an even bit 
        // (1-based indexing for bits)
        
        for(int i = 0 ; i < 32 ; i+=2){
            if(n & 1<<i){
                return true;
            }
        }
        
        // the set bit must have be on an odd bit
        // therefore our number is not a power of 4, therefore return false
        
        return false;
        
        
        
        // ---------------------------------------------------
        
//         // TC - O(logn), SC  - O(1)
//         if(n == 0){
//             return false;
//         }
//         if(n == 1){
//             return true;
//         }
        
//         while(n>1){
//             if(n%4 != 0){
//                 cout << "n = " << n << endl;
//                 return false;
//             }
//             else{
//                 n/=4;
//             }
//         }
        
//         return n==1;
        
        
//         // return n%4 == 0 && isPowerOfFour(n/4); -> TC - O(logn), SC - O(logn)
        
    }
};