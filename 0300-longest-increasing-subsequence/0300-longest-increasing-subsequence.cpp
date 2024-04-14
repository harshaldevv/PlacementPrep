class Solution {
public:
    int f(int i, int previndex, vector<int> &nums, vector<vector<int>> &dp){
        if(i >= nums.size()){
            return 0;
        }
        
        int j = previndex;
        if(dp[i][j +1] != -1){
            return dp[i][j+1];
        }
        // not take 
        int nottake = f(i+1, previndex, nums, dp);
        
        int take = 0;
        if(previndex == -1 || nums[i] > nums[previndex]){
            take = 1 + f(i+1, i, nums, dp);
        }
        
        return dp[i][j+1] = max(take, nottake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        int previndex = -1;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return f(0, previndex, nums, dp);
        
    }
};