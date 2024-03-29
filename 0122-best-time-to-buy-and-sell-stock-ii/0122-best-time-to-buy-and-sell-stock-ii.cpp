class Solution {
public:
    int f(int i, vector<int> &prices, bool youcanBuy, vector<vector<int>> &dp){
        
        if(i>=prices.size()){
            return 0;
            //end of the days
        }
        
        if(dp[i][youcanBuy] != -1){
            return dp[i][youcanBuy];
        }
        
        if(youcanBuy){
            //two options -> buy or not buy
            int notBuy = f(i+1, prices, true, dp);
            int iBuy = -prices[i] + f(i+1, prices, false, dp);
            return dp[i][youcanBuy] = max(notBuy, iBuy);
        }
        else{
            //sell or not sell
            int notsell = f(i+1, prices, false, dp);
            int sell = prices[i] + f(i+1, prices, true, dp);
            
            return dp[i][youcanBuy] = max(sell, notsell);
        }
        
        
        
        
    }
    int maxProfit(vector<int>& prices) {
        //maybe knapsack pattern
        int n = prices.size();
        // bool youcanBuy = true;
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));        
        // return f(0, prices, youcanBuy, dp);
        
//         // tabulation
//         vector<vector<int>> dp(n+1, vector<int>(2, 0));        
//         for(int i = n-1 ; i >=0 ; i--){
//             for(int j = 0 ; j <= 1 ; j++){
                
//                 if(j){
//                     //two options -> buy or not buy
//                     int notBuy = dp[i+1][true];
//                     int iBuy = -prices[i] + dp[i+1][false];
//                     dp[i][j] = max(notBuy, iBuy);
//                 }
//                 else{
//                     //sell or not sell
//                     int notsell = dp[i+1][false];
//                     int sell = prices[i] + dp[i+1][true];

//                     dp[i][j] = max(sell, notsell);
//                 }  
//             }
//         }
        
//         return dp[0][1];
        
        
//         /*
//         GREEDY METHOD
//         There is a classical saying in the stock market - "Buy the Dip".
//         Same concept you need to apply here
//         Compare two consecutive days and if you are making a profit, 
//         just buy on 1st day and sell on 2nd day
//         */
        int ans = 0;
        for(int i = 1 ; i < n ;i++){
            if(prices[i] >= prices[i-1]){
                ans += prices[i] - prices[i-1];
            }
        }
        
        return ans;
        
        
        
        
        
        
        
        
        
        
//         // tabulation with space optimization
//         vector<int> after(2, 0);        
//         vector<int> curr (2, 0);
        
//         for(int i = n-1 ; i >=0 ; i--){
//             for(int j = 0 ; j <= 1 ; j++){
                
//                 if(j){
//                     //two options -> buy or not buy
//                     int notBuy = after[true];
//                     int iBuy = -prices[i] + after[false];
//                     curr[j] = max(notBuy, iBuy);
//                 }
//                 else{
//                     //sell or not sell
//                     int notsell = after[false];
//                     int sell = prices[i] + after[true];
//                     curr[j] = max(sell, notsell);
//                 }  
//             }
            
//             after = curr;
//         }
        
//         return curr[1];
        
        
        
        
        
        
        
        
    }
};