class Solution {
public:
    int countSetBits(uint32_t n){
        int ans = 0;
        
        while(n){
            ans++;
            n = n&(n-1);
        }
        return ans;
    }
    int hammingWeight(uint32_t n) {
        
        // return __builtin_popcount(n); --> using inbuilt function
        
        // without inbuilt func
        return countSetBits(n);
        
    }
};