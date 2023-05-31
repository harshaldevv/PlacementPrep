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
        // bool youcanbuy = true;
        // vector<vector<int>> dp(n+1, vector<int>(3, -1));
        // return f(0, youcanbuy, prices, fees, dp);
        
//         //tabulation
//         vector<vector<int>> dp(n+1, vector<int>(3, 0));
//         // i -> 0 to n-1 --> here n-1 to 0;
//         // 1 --> 0 to 1
        
//         for(int i = n-1 ; i>= 0; i--){
//             for(int j = 0 ; j <= 1 ; j++){
                
//                 if(j){
//                     //buy, not buy
//                     int buy = -prices[i] - fees + dp[i+1][false];
//                     int notbuy = dp[i+1][true];
                    
//                     dp[i][j] = max(buy, notbuy);
//                 }
//                 else{
//                     //sell, not sell
//                     int sell = +prices[i] + dp[i+1][true];
//                     int notsell = dp[i+1][false];

//                     dp[i][j] = max(sell, notsell);
//                 }
                
//             }
//         }
        
//         return dp[0][1];
        
        
        //tabulation with space optimisation
        vector<int> after(3, 0);
        vector<int> curr(3, 0);
        
        // i -> 0 to n-1 --> here n-1 to 0;
        // 1 --> 0 to 1
        
        for(int i = n-1 ; i>= 0; i--){
            for(int j = 0 ; j <= 1 ; j++){
                
                if(j){
                    //buy, not buy
                    int buy = -prices[i] - fees + after[false];
                    int notbuy = after[true];
                    
                    curr[j] = max(buy, notbuy);
                }
                else{
                    //sell, not sell
                    int sell = +prices[i] + after[true];
                    int notsell = after[false];

                    curr[j] = max(sell, notsell);
                } 
            }
            
            after = curr;
        }
        
        return after[1];
        
        
        
    }
};