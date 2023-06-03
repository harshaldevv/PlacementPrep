class Solution {
public:
//     int f(int i, bool youcanbuy, int c, vector<int> &prices, vector<vector<vector<int>>> &dp){
//         if(i >= prices.size()){
//             return 0;
//         }
        
//         if(c > 2 ){
//             return 0;
//         }
        
//         if(dp[i][youcanbuy][c] != -1){
//             return dp[i][youcanbuy][c] ;
//         }
        
//         if(youcanbuy){
//             //buy, not buy
//             int buy = -prices[i] + f(i+1, false, c+1, prices, dp);
//             int notbuy = f(i+1, true, c, prices, dp);
//             return dp[i][youcanbuy][c]  = max(buy, notbuy);
//         }
//         else{
//             // sell, not sell
//             int sell = +prices[i] + f(i+1, true, c, prices, dp);
//             int notsell = f(i+1, false, c, prices, dp);
            
//             return dp[i][youcanbuy][c] =  max(sell, notsell);
//         }
//     }
    int ff(int i, int tc, vector<int> &prices, vector<vector<int>> &dp){
        if(i >= prices.size()){
            return 0;
        }
        
        if(tc >= 4){
            return 0;
        }
        
        if(dp[i][tc] != -1){
            return dp[i][tc];
        }
        
        if(tc%2 == 0){
            //buy
            // buy, not buy
            int buy = -prices[i] + ff(i+1, tc+1, prices, dp);
            int notbuy = ff(i+1, tc, prices, dp);
            return dp[i][tc] =  max(buy, notbuy);
        }
        else{
            //sell
            // sell, not sell
            int sell = +prices[i] + ff(i+1, tc+1, prices, dp);
            int notsell = ff(i+1, tc, prices, dp);
            
            return dp[i][tc] =  max(sell, notsell);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
//         bool youcanbuy = true;
//         int counter = 0;
        
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(4, -1)));
//         return f(0, youcanbuy, counter, prices, dp);
        
        // int transactionCounter = 0;
        // vector<vector<int>> dp(n+1, vector<int>(5, -1));
        // return ff(0, transactionCounter, prices, dp);
        

        //do tabulation wala code.
        
        vector<vector<int>> dp(n+1, vector<int>(5, 0));
        for(int i = n -1 ; i >= 0 ; i--){
            for(int j = 3 ; j>=0 ; j--){
                
                
                if(j%2 == 0){
                    //buy
                    // buy, not buy
                    int buy = -prices[i] + dp[i+1][j+1];
                    int notbuy = dp[i+1][j];
                    dp[i][j] =  max(buy, notbuy);
                }
                else{
                    //sell
                    // sell, not sell
                    int sell = +prices[i] + dp[i+1][j+1];
                    int notsell = dp[i+1][j];

                    dp[i][j] =  max(sell, notsell);
                }
                
            }
        }
        
        return dp[0][0];
        
        
    }
    
};