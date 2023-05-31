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
        // bool youcanbuy = true;
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(3, -1)));
        // return f(0, youcanbuy, 0, prices, dp);
        
        //tabulation
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(4, -1)));
        
        //base case
        dp[n][0][0] = 0;
        dp[n][0][1] = 0;
        dp[n][0][2] = 0;
        
        dp[n][1][0] = 0;
        dp[n][1][1] = 0;
        dp[n][1][2] = 0;
        
        for(int i = n-1 ; i>= 0 ; i--){ // index
            for(int j = 0; j<= 1 ; j++){ // youcanbuy
                for(int k = 0; k <= 2 ; k++){ //count
                    
                    if(j){
                        // buy, not buy
                        int buy = -prices[i] + dp[i+1][false][k+1];
                        int notbuy = dp[i+1][true][k];
                        dp[i][j][k] = max(buy, notbuy);
                    }
                    else{
                        //sell, notsell
                        int sell = +prices[i] + dp[i+1][true][k];
                        int notsell  = dp[i+1][false][k];
                        dp[i][j][k] = max(sell, notsell);
                    }
                }
            }
        }
        
        return dp[0][1][0];
    }
};