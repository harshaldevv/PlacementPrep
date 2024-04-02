class Solution {
public:
    int f(int i, vector<int> &prices, bool toBuy, vector<vector<int>> &dp){
        if( i >= prices.size()){
            return 0;
        }
        
        if(dp[i][toBuy] != -1){
            return dp[i][toBuy];
        }
        
        if(toBuy){
            int buy = -prices[i] + f(i+1, prices, false, dp);
            int notbuy = f(i+1, prices, true, dp);
            return dp[i][toBuy] = max(buy, notbuy);
        }
        else{
            int sell = +prices[i] + f(i+2, prices, true, dp);
            int notsell =  f(i+1, prices, false, dp);
            return dp[i][toBuy] =  max(sell, notsell);
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        return f(0, prices, true, dp);
        
    }
};