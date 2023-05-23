class Solution {
public:
    
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(j == 0){
            return 1;
        }
        
        if(i == 0){
            if(j%nums[i] == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
    
        int nottake = f(i-1, j, nums, dp);
        int take = 0;
        
        if(j >= nums[i]){
            take =  f(i, j - nums[i], nums, dp );
        }
        // cout << "i, j = " << i << ", " << j << " : " << nottake << " + " << take << endl;
        return dp[i][j] = take + nottake;
    }
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        // vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        // return f(n-1, amount, coins, dp);
        
        int dp[n][amount+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0 ; i < n ; i++){
            dp[i][0] = 0;
        }
        
        vector<int> nums = coins;
        for(int j = 0 ; j <= amount ; j++){
            if(j%nums[0] == 0){
                dp[0][j] =  1;
            }
            else{
                dp[0][j] =  0;
            }
        }
        
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j <= amount ; j++){
                
                int nottake = dp[i-1][j];
                int take = 0;

                if(j >= nums[i]){
                    take =  dp[i][j - nums[i]];
                }
                
                dp[i][j] = take + nottake;
                
            }
        }
        
        return dp[n-1][amount];
        
        
//         int  n = coins.size();
//         int  W = amount;
        
//         int t[n+1][W+1];
//         //mapping it to Knapsack (unbounded) but with different intialization
       
//         memset(t, -1, sizeof(t));
        
//         // fill first row with 0;
//         for(int  j = 0 ; j < W +1 ; j++){
//             t[0][j] = 0;
//         }
        
//         // fill first col with 1
//         for(int i = 0 ; i < n+1 ; i++){
//             t[i][0] = 1;
//         }
        
//         for(int i =1 ; i < n+1 ; i++){
//             for(int j = 1 ; j < W+1; j++){
//                 if(coins[i-1] <= j){
//                     t[i][j] = t[i-1][j] + t[i][j-coins[i-1]];
//                 }
//                 else{
//                     t[i][j] = t[i-1][j];
//                 }
//             }
//         }
        
//         return t[n][W];
    }
};