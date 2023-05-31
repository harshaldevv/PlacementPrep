class Solution {
public:
    
    int f(int i, int youcanbuy, vector<int> &prices, vector<vector<int>> &dp){
        if(i >= prices.size()){
            return 0;
        }
        
        if(dp[i][youcanbuy] != -1){
            return dp[i][youcanbuy] ;
        }
        
        if(youcanbuy){
            int notbuy = f(i+1, true, prices, dp);
            int buy = -prices[i] + f(i+1, false, prices, dp);
            return dp[i][youcanbuy]  = max(buy, notbuy);
        }
        else{
            int notsell = f(i+1, false, prices, dp);
            int sell = f(i+2, true, prices, dp) + prices[i];
            return dp[i][youcanbuy]  = max(sell, notsell);
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        // bool youcanbuy = true;
        // vector<vector<int>> dp(n+1, vector<int>(2+1, -1));
        // return f(0, youcanbuy, prices, dp);
        
        
        //tabulation
        vector<vector<int>> dp(n+2, vector<int>(3, 0));
        
        for(int i = n-1; i >= 0 ; i--){
            for(int j = 0 ; j <=1 ; j++){
                
                if(j){
                    int notbuy = dp[i+1][true];
                    int buy = -prices[i] + dp[i+1][false];
                    dp[i][j]  = max(buy, notbuy);
                }
                else{
                    int notsell = dp[i+1][false];
                    int sell = dp[i+2][true] + prices[i];
                    dp[i][j]  = max(sell, notsell);
                }
                
            }
        }
        
        return dp[0][1];
        
        
    }
};