class Solution {
public:
    int helper(int i, vector<int> &nums, vector<int> &dp){
        if(i < 0){
            return 0;
        }
        
        if( i == 0){
            return dp[i] = nums[i];
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        int pick = nums[i] + helper(i-2, nums, dp);
        int notpick = helper(i-1, nums, dp);
        
        return dp[i] =  max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return helper(n-1, nums, dp);
        
    }
};