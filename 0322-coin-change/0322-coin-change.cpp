class Solution {
public:
    
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(j == 0){
            return 0;
        }
        
        if(i == 0){
            if(j%nums[i] == 0){
                return j/nums[i];
            }
            else{
                return 1e5;
                // agar nahi ban paa raha , toh no of coins req = INT MAX
                // kyuki jitna bhi try karlo, nahi banega
            }
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int nottake = f(i-1, j, nums, dp );
        
        int take = INT_MAX;
        
        if(j >= nums[i]){
            take = 1 +  f(i, j- nums[i], nums, dp) ;
        }
        
        return dp[i][j] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        
        // knapsack
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        //striver method
        int ans =  f(n-1, amount, coins, dp);
        
        if(ans >= 1e5){
            return -1;
        }
        
        return ans;
        
    }
};