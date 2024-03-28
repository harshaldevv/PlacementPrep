class Solution {
public:
    
    int helper(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i < 0 || j < 0){
            return false;
        }
        
        if(j == 0){
            return dp[i][j] = true;
        }
        
        if(i == 0){
            return dp[i][j] =  nums[i] == j;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        bool take = false;
        bool nottake = false;
        
        nottake= helper(i-1, j, nums, dp);
        
        take = helper(i-1, j - nums[i], nums, dp);
        
        return dp[i][j] =  take ||nottake;
    }
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        
        for(auto &x : nums){
            sum +=x;
        }
        
        if(sum%2 != 0){
            return false;
        }
        
        int n = nums.size() ;
        vector<vector<int>> dp(n+1, vector<int>(sum/2 +1, -1 ));
        return helper(n-1, sum/2, nums, dp);
        
    }
};