class Solution {
public:
    int f(int i, vector<int> &prices, bool toBuy, int counter, vector<vector<vector<int>>> &dp ){
        if(i >= prices.size() || counter >= 4 ){
            return 0;
        }
        
        if(dp[i][toBuy][counter] != -1){
            return dp[i][toBuy][counter];
        }
        if(toBuy){
            int buy = -prices[i] + f(i+1, prices, false, counter+1, dp);
            int notbuy = f(i+1, prices, true, counter, dp);
            return dp[i][toBuy][counter] = max(buy, notbuy);
        }
        else{
            int sell = +prices[i] + f(i+1, prices, true, counter +1, dp);
            int notsell = f(i+1, prices, false, counter, dp);
            return dp[i][toBuy][counter] =  max(sell, notsell);
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int transactionCounter = 0;
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(5, -1)));
        return f(0, prices, true, transactionCounter, dp);
        
    }
};