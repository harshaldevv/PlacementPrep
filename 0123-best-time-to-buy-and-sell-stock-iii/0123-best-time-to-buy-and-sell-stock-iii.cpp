class Solution {
public:
    int f(int i, bool canbuy, int k, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if( i >= prices.size() || k == 0){
            return 0;
        }

        int j = canbuy;

        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }

        if(canbuy){
            // i can buy -> so i have 2 options -> buy or skip
            int buy  = -prices[i] + f(i+1, false, k, prices, dp);
            int skip = f(i+1, true, k, prices, dp);

            return dp[i][j][k] = max(buy, skip);
        }
        else{
            // i cant buy -> so i have 2 options -> skip or sell
            int skip = f(i+1, false, k, prices, dp);
            int sell = +prices[i] + f(i+1, true, k-1, prices, dp); // decrement k because ONE TRANSACTION IS COMPLETE

            return dp[i][j][k] =  max(skip, sell);
        }
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int k = 2;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (3, vector<int>(k+1, -1)));
        return f(0, true, k, prices, dp);
        
    }
};