class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
//         return profit(nums, n-1);
        
        vector<int> dp(n, -1);
        return profitMemoized(nums, n-1, dp);   
    }
    
    int profitMemoized(vector<int> &cost, int n, vector<int> &dp){
        if(n<0){
            return 0;
        }
        
        if(n==0){
            dp[n] = cost[n];
            return cost[n];
        }
        
        if(n==1){
            dp[n]  = max(cost[n-1], cost[n]);
            return dp[n];
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        dp[n] = max(cost[n] + profitMemoized(cost, n-2, dp), profitMemoized(cost, n-1, dp));
        
        return dp[n];
    }
    
    long profit(vector<int> &cost, int n){
        
        if(n<0){
            return 0;
        }
        
        if(n==0){
            return cost[n];
        }
        
        if(n==1){
            return max(cost[n-1], cost[n]);
        }
        
        
        return max(cost[n] + profit(cost, n-2), profit(cost, n-1));
    }
};