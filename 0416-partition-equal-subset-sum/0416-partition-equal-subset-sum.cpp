class Solution {
public:
    int f(int i, int tar, vector<int> &nums, vector<vector<int>> &dp){
        if(tar == 0){
            return true;
        }
        
        if(i == 0){
            return nums[i] == tar;
        }
        
        if(dp[i][tar] != -1){
            return dp[i][tar];
        }
        
        bool nottake = f(i-1, tar, nums, dp);
        
        bool take = false;
        if(tar >= nums[i]){
            take = f(i-1, tar - nums[i], nums, dp);
        }
        
        return dp[i][tar] =  take | nottake;
    }
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        int s = 0;
        for(auto &x : nums){
            s+= x;
        }
        
        if(s%2 != 0){
            return false;
        }
        
        
        vector<vector<int>> dp(n+1, vector<int> (s/2 +1, -1));
        return f(n-1, s/2, nums, dp);
        
    }
};