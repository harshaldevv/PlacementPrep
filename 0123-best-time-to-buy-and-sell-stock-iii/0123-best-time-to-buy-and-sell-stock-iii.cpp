class Solution {
public:
    int f(int i, bool youcanbuy, int c, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(i >= prices.size()){
            return 0;
        }
        
        if(c > 2 ){
            return 0;
        }
        
        if(dp[i][youcanbuy][c] != -1){
            return dp[i][youcanbuy][c] ;
        }
        
        if(youcanbuy){
            //buy, not buy
            int buy = -prices[i] + f(i+1, false, c+1, prices, dp);
            int notbuy = f(i+1, true, c, prices, dp);
            return dp[i][youcanbuy][c]  = max(buy, notbuy);
        }
        else{
            // sell, not sell
            int sell = +prices[i] + f(i+1, true, c, prices, dp);
            int notsell = f(i+1, false, c, prices, dp);
            
            return dp[i][youcanbuy][c] =  max(sell, notsell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        bool youcanbuy = true;
        int counter = 0;
        // vector<vector<vector<int>>> dp
        
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(4, -1)));
        return f(0, youcanbuy, counter, prices, dp);
    }
};