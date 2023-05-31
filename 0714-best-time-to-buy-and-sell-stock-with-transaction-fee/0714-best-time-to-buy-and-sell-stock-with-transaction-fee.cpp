class Solution {
public:
    int f(int i, bool youcanbuy, vector<int>&prices, int &fees, vector<vector<int>> &dp){
        if(i >= prices.size()){
            return 0;
        }
        
        if(dp[i][youcanbuy] != -1){
            return dp[i][youcanbuy];
        }
        
        if(youcanbuy){
            //buy, not buy
            int buy = -prices[i] - fees + f(i+1, false, prices, fees, dp);
            int notbuy = f(i+1, true, prices, fees, dp);
            return dp[i][youcanbuy] = max(buy, notbuy);
        }
        else{
            //sell, not sell
            int sell = +prices[i] + f(i+1, true, prices, fees, dp);
            int notsell = f(i+1, false, prices, fees, dp);
            
            return dp[i][youcanbuy] = max(sell, notsell);
        }
        
        
    }
    int maxProfit(vector<int>& prices, int &fees) {
        
        int n = prices.size();
        bool youcanbuy = true;
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        return f(0, youcanbuy, prices, fees, dp);
        
    }
};