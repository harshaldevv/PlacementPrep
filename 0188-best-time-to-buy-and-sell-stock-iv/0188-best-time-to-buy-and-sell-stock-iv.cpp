class Solution {
public:
    int f(int i, bool youcanbuy, int buycount, vector<int> &prices, int &k, vector<vector<vector<int>>> &dp){
        /*
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
        */
        
        return -1 ; // dummy return kyuki poora func mene comment kar dia hai isliye
    }
    
    int func(int i, int transactionCounter, int &k, vector<int> &prices, vector<vector<int>> &dp){
        if(i == prices.size() ){
            return 0;
        }
        
        if(transactionCounter == 2*k){
            return 0;
        }
        
        if(dp[i][transactionCounter] != -1){
            return dp[i][transactionCounter];
        }
        
        if(transactionCounter%2 == 0){
            //buy allowed -->now you can either buy or not
            int buy = -prices[i] + func(i+1, transactionCounter +1, k, prices, dp);
            int notbuy = func(i+1, transactionCounter, k, prices, dp);
            return dp[i][transactionCounter] = max(buy, notbuy);
        }
        else{
            int sell = +prices[i] + func(i+1, transactionCounter+1, k, prices, dp);
            int notsell = func(i+1, transactionCounter, k, prices, dp);
            return dp[i][transactionCounter] = max(sell, notsell);
        }
        
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // bool youcanbuy = true;
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(k+1, -1)));
        // return f(0, youcanbuy, 0, prices, k, dp);
        
        // using different idea -> keeping a transaction counter -> 
        // could have been used in Best Time to Buy and Sell Stock III
        
        
        // vector<vector<int>> dp(n+1, vector<int>(2*k +1, -1));
        // return func(0, 0, k, prices, dp);
        
        //this works like a charm
        
        
//         // now doing tabulation
//         vector<vector<int>> dp(n+1, vector<int>(2*k +1, 0));
        
//         //base case already done via our initialisation of "0"
        
//         for(int i = n-1 ; i >=0 ; i--){
//             for(int j = 2*k -1 ; j >=0 ; j--){
                
//                 if(j%2 == 0){
//                     //buy allowed -->now you can either buy or not
//                     int buy = -prices[i] + dp[i+1][j +1];
//                     int notbuy = dp[i+1][j];
//                     dp[i][j] = max(buy, notbuy);
//                 }
//                 else{
//                     int sell = +prices[i] + dp[i+1][j+1];
//                     int notsell = dp[i+1][j];
//                     dp[i][j] = max(sell, notsell);
//                 }
//             }
//         }
        
//         return dp[0][0];
        
        
        // now doing tabulation with space optimization
        vector<int> after(2*k +1, 0);
        vector<int> curr(2*k +1, 0);
        
        //base case already done via our initialisation of "0"
        
        for(int i = n-1 ; i >=0 ; i--){
            for(int j = 2*k -1 ; j >=0 ; j--){
                
                if(j%2 == 0){
                    //buy allowed -->now you can either buy or not
                    int buy = -prices[i] + after[j +1];
                    int notbuy = after[j];
                    curr[j] = max(buy, notbuy);
                }
                else{
                    int sell = +prices[i] + after[j+1];
                    int notsell = after[j];
                    curr[j] = max(sell, notsell);
                }
            }
            
            after = curr;
        }
        
        return curr[0];
        
        
        
        
        
    }
};