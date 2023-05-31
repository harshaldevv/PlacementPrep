class Solution {
public:
    int f(int i, bool youcanbuy, int count, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(i==prices.size()){
            return 0;
        }
        
        if(count > 2){
            return 0;
        }
        
        if(dp[i][youcanbuy][count] != -1){
            return dp[i][youcanbuy][count];
        }
        
        if(youcanbuy){
            // buy, not buy
            int buy = -prices[i] + f(i+1, false, count+1, prices, dp);
            int notbuy = f(i+1, true, count, prices, dp);
            return dp[i][youcanbuy][count] = max(buy, notbuy);
        }
        else{
            //sell, notsell
            int sell = +prices[i] + f(i+1, true, count, prices, dp);
            int notsell  = f(i+1, false, count, prices, dp);
            return dp[i][youcanbuy][count] = max(sell, notsell);
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        // max buy 2 times
        bool youcanbuy = true;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(5, vector<int>(5, -1)));
        return f(0, youcanbuy, 0, prices, dp);
    }
};