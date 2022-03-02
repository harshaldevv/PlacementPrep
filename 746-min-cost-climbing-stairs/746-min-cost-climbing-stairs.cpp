class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //return min(helper(n-1, cost), helper(n-2, cost));
        
        vector<int> t(n, -1);
        return min(helper2(n-1, cost, t), helper2(n-2, cost, t));
        
    }
    
    int helper2(int n, vector<int> &cost, vector<int> &dp){
        if(n <0 ){
            return 0;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        if(n== 0 || n == 1){
            dp[n] = cost[n];
            return cost[n];
        }
        
        int ans =  cost[n] + min(helper2(n-1, cost, dp), helper2(n-2, cost, dp));
        dp[n] = ans;
        
        return ans;
    }
    
    int helper(int n, vector<int> &cost){
        if(n<0){
            return 0;
        }
        if(n == 1 || n==0){
            return cost[n];
        }
        
        return cost[n] + min(helper(n-1, cost), helper(n-2, cost));
    }
};