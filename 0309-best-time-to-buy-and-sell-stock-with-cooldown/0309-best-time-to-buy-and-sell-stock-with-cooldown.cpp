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
        bool youcanbuy = true;
        
        vector<vector<int>> dp(n+1, vector<int>(2+1, -1));
        return f(0, youcanbuy, prices, dp);
        
    }
};