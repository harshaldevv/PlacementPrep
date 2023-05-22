class Solution {
public:
    bool f(int i, int j, vector<int> &nums, vector<vector<int>> &dp ){
        // cout << i << " , " << j << endl;
        
        if(j == 0){
            return true;
        }
        
        if(i == 0 ){
            return nums[i] == j;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        
        bool notTake = f(i-1, j, nums, dp);

        bool take = false;
        
        if(j >= nums[i]){
            take = f(i-1, j - nums[i], nums, dp);
        }
        
        return dp[i][j] = take | notTake;
        
    }
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        int s = 0;
        for(auto &x : nums){
            s+=x;
        }
        
        if(s%2 !=0){
            return false;
        }
        
        int ss = s/2;
        // vector<vector<int>> dp(n, vector<int>(ss+1, -1));
        
        // return f(n-1, ss, nums, dp);
        
        // tabulation
        // vector<vector<int>> dp(n, vector<int>(ss+1, -1));
        
        bool dp[n][ss+200];
        memset(dp, false, sizeof(dp));
        
        for(int i = 0 ; i < n ; i++){
            dp[i][0] = false;
        }
        
        dp[0][nums[0]] = true;
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j <= ss; j++){
                bool notTake = dp[i-1][j];
                
                bool take = false;
                
                if( j >= nums[i]){
                    take = dp[i-1][j-nums[i]];
                }
                
                dp[i][j] = notTake || take;
            }
        }
        
        
        return dp[n-1][ss];
        
        
        
    }
};