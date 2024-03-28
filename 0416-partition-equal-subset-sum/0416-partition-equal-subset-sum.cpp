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
        
        
        // vector<vector<int>> dp(n+1, vector<int> (s/2 +1, -1));
        // return f(n-1, s/2, nums, dp);
        
        bool dp[n+1][s +1];
        
        memset(dp, false, sizeof(dp));
        //basecase
        for(int i = 0 ;i < n ; i++){
            dp[i][0] = true;
        }
        
        dp[0][nums[0]] = true;
        
        int tar = s/2;
        for(int i = 1 ; i < n; i++){
            for(int j= 1 ; j <= tar; j++){
                
                bool nottake = dp[i-1][j];
                bool take = false;
                if(j >= nums[i]){
                    take = dp[i-1][j - nums[i]];
                }

                dp[i][j] =  take | nottake;
                
            }
        }
        
        return dp[n-1][tar];
        
    }
};