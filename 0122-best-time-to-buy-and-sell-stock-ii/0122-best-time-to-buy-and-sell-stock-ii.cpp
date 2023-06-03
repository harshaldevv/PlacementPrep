class Solution {
public:
    
    int f(int i, bool canyoubuy, vector<int> &prices, vector<vector<int>> &dp){
        
        if(i >= prices.size()){
            return 0;
        }
        
        if(dp[i][canyoubuy] != -1){
            return dp[i][canyoubuy];
        }
        
        if(canyoubuy){
            // buy, not buy
            int buy = -prices[i] + f(i+1, false, prices, dp);
            int notbuy = f(i+1, true, prices, dp);
            
            return dp[i][canyoubuy] = max(buy, notbuy);
        }
        else{
            // sell, not sell
            int sell = +prices[i] + f(i+1, true, prices, dp);
            int notsell = f(i+1, false, prices, dp);
            return dp[i][canyoubuy] = max(sell, notsell);
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        bool youcanbuy = true;
        
        
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return f(0, youcanbuy, prices, dp);
        
        
        //tabulation
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        for(int i = n-1 ; i >=0 ; i--){
            for(int j = 0 ; j <= 1 ; j++){
                if(j){
                    // buy, not buy
                    int buy = -prices[i] + dp[i+1][false];
                    int notbuy = dp[i+1][true];

                    dp[i][j] = max(buy, notbuy);
                }
                else{
                    // sell, not sell
                    int sell = +prices[i] + dp[i+1][true];
                    int notsell = dp[i+1][false];
                    
                    dp[i][j] = max(sell, notsell);
                }
            }
        }
        
        return dp[0][true];
        
        
    }
};