class Solution {
public:
    int f(int i, bool canbuy, int &fees, vector<int> &prices, vector<vector<int>> &dp){
        
        if( i>= prices.size()){
            return 0;
        }

        int j = canbuy;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(canbuy){
            // i can buy -> buy or skip

            int buy = -prices[i] + f(i+1, false, fees, prices, dp);
            int skip = f(i+1, true, fees, prices, dp);
            return dp[i][j] = max(buy, skip);
        }
        else{
            // i cannot buy -> hold or sell
            int hold = f(i+1, false,  fees, prices, dp);
            int sell = +prices[i] - fees + f(i+1, true, fees, prices, dp);
            return dp[i][j] = max(hold, sell);
        }


    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return f(0, true, fee, prices, dp);


        // vector<vector<int>> dp(n+1, vector<int>(2, 0));

        // // n-1 to 0
        // // false to true

        // for(int i = n-1 ; i>= 0; i--){
        //     for(int j = 0 ; j <= 1; j++){
        //         bool canbuy = j;

        //         if(canbuy){
        //             // i can buy -> buy or skip
        //             int buy = -prices[i] + dp[i+1][false];
        //             int skip = dp[i+1][true];
        //             dp[i][j] = max(buy, skip);
        //         }
        //         else{
        //             // i cannot buy -> hold or sell
        //             int hold = dp[i+1][false];
        //             int sell = +prices[i] - fee + dp[i+1][true];
        //             dp[i][j] = max(hold, sell);
        //         } 
        //     }
        // }

        // return dp[0][true];

        
        // -------

        // n-1 to 0
        // false to true
        vector<int> curr(2, 0);
        vector<int> ahead(2, 0);

        for(int i = n-1 ; i>= 0; i--){
            for(int j = 0 ; j <= 1; j++){
                bool canbuy = j;

                if(canbuy){
                    // i can buy -> buy or skip
                    int buy = -prices[i] + ahead[false];
                    int skip = ahead[true];
                    curr[j] = max(buy, skip);
                }
                else{
                    // i cannot buy -> hold or sell
                    int hold = ahead[false];
                    int sell = +prices[i] - fee + ahead[true];
                    curr[j] = max(hold, sell);
                } 
            }

            ahead = curr;
        }

        return ahead[true];
        
    }

};