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
        // return f(n-1, nums, dp);
        
//         dp[0] = nums[0];
//         dp[1] = max(nums[0], nums[1]);
        
//         for(int i = 2 ; i < n ; i++){
//             int nottake = dp[i-1];
//             int take = dp[i-2] + nums[i];

//             dp[i] =  max(take, nottake);
//         }
        
//         return dp[n-1];
        
        
        if(n ==1){
            return nums[0];
        }
        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);
        
        for(int i = 2 ; i < n ; i++){
            int nottake = prev;
            int take = prev2 + nums[i];
            
            int curr = max(take, nottake);
            
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
        
        
        
        
    }
};