class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        //hci research 
        
        int count = 0;
        while (n > 0) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
};
