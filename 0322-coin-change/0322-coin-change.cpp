class Solution {
public:
    int f(int i, int j, vector<int> coins, vector<vector<int>> &dp){
        if(i < 0 || j < 0 ){
            return 1e5;
        }
        
        if(i == 0){
            if(j%coins[i] == 0){
                return dp[i][j] = j/coins[i];
            }
            else{
                return dp[i][j] =  1e5;
            }
        }
        
        if(j == 0){
            return dp[i][j] = 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }
        
        int nottake = f(i-1, j, coins, dp);
        int take = INT_MAX;
        if(j >= coins[i]){
            take = 1 + f(i, j - coins[i], coins, dp);
        }
        
        return dp[i][j] =  min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount +1 , -1));
        int ans =  f(n-1, amount, coins, dp);
        
        if(ans >= 1e5){
            return -1;
        }
        
        return ans;
        
    }
};