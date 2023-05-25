class Solution {
public:
    
    int f(int i, vector<int> &nums, vector<int> &dp){
        if(i == 0){
            return nums[i];
        }
        if(i==1){
            return max(nums[0], nums[1]);
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        int nottake = f(i-1, nums, dp);
        int take = f(i-2, nums, dp) + nums[i];
        
        return dp[i] =  max(take, nottake);
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return f(n-1, nums, dp);
        
    }
};