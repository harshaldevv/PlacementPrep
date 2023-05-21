class Solution {
public:
    int f(int i, vector<int> &nums, vector<int> &dp){
        if(i == 0){
            return nums[0];
        }
        else if(i == 1){
            return max(nums[0], nums[1]);
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        int left = f(i-1, nums, dp);
        int right = f(i-2, nums, dp) + nums[i];
        
        return dp[i] =  max(left, right);
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return f(n-1, nums, dp);
        
    }
};