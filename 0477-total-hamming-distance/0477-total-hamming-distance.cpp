class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        // similar to interview bit -> Different Bits Sum Pairwise
        // https://www.interviewbit.com/problems/different-bits-sum-pairwise/
        int ans = 0;
        for(int i = 0 ; i< 32 ; i++){
            int zeroes = 0;
            int ones = 0;
            
            for(auto &x : nums){
                if(x >> i & 1){
                    ones++;
                }
                else{
                    zeroes++;
                }
            }
            
            ans += (zeroes*ones);
        }
        
        return ans;
    }
};