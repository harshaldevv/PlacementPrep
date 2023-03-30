class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // this is dp;
        // not backtracking
        
        // hci research
        
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i >= nums[j]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};