class Solution {
public:
    int f(int i, bool youcanbuy, int buycount, vector<int> &prices, int &k, vector<vector<vector<int>>> &dp){
        if(i== prices.size()){
            return 0 ;
        }
        
        if(buycount > k){
            return 0;
        }
        
        if(dp[i][youcanbuy][buycount] != -1){
            return dp[i][youcanbuy][buycount];
        }
        
        if(youcanbuy){
            //buy, notbuy
            int buy = -prices[i] + f(i+1, false, buycount+1, prices, k, dp);
            int notbuy = f(i+1, true, buycount, prices, k, dp);
            return dp[i][youcanbuy][buycount] = max(buy, notbuy);
        }
        else{
            // sell , notsell
            int sell = +prices[i] + f(i+1, true, buycount, prices, k, dp);
            int notsell = f(i+1, false, buycount, prices, k, dp);
            
            return dp[i][youcanbuy][buycount] = max(sell, notsell);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        bool youcanbuy = true;
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(k+1, -1)));
        return f(0, youcanbuy, 0, prices, k, dp);
        
    }
};