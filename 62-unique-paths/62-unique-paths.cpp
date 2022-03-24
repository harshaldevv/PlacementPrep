class Solution {
public:
    int dp[100+1][100+1];
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return helper(m,n);
    }
    
    int helper(int m, int n){
        if(m==1 || n ==1){
            dp[m][n] = 1;
            return 1;
        }
        
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        
        dp[m][n] =  helper(m,n-1) + helper(m-1, n);
        return dp[m][n];
        
    }
};