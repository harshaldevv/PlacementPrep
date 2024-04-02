class Solution {
public:
    int f(int i, bool canbuy, vector<int> &prices, vector<vector<int>> &dp){
        if(i>= prices.size()){
            return 0;
        }
        
        if(dp[i][canbuy] != -1){
            return dp[i][canbuy];
        }
        
        if(canbuy){
            //buy, not buy
            int buy = -prices[i] + f(i+1, false, prices, dp);
            int notbuy = f(i+1, true, prices, dp);
            return  dp[i][canbuy] = max(buy, notbuy);
        }
        else{
            //sell
            // sell, not sell
            int sell = +prices[i] + f(i+2, true, prices, dp);
            int notsell = f(i+1, false, prices, dp);
            return dp[i][canbuy] =  max(sell, notsell);
            
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return f(0, true, prices, dp);
        
        
        vector<vector<int>> dp(n+2, vector<int>(3, 0));
        
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = 0 ; j <= 1 ; j++){
                if(j){
                    //buy, not buy
                    int buy = -prices[i] +  dp[i+1][false];
                    int notbuy = dp[i+1][true];
                    dp[i][j] = max(buy, notbuy);
                }
                else{
                    //sell
                    // sell, not sell
                    
                    int notsell = dp[i+1][false];
                    int sell = +prices[i] + dp[i+2][true];   
    
                
                    dp[i][j] =  max(sell, notsell);
                }
            }
        }
        
        return dp[0][true];
        
    }
};