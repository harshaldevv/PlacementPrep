class Solution {
public:
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i == 0 & j == 0){
            return grid[i][j];
        }
        
        if(i < 0 || j < 0 ){
            return INT_MAX;
        }
        if(dp[i][j]!= -1){
            return dp[i][j];
        }
        int up = f(i-1, j, grid, dp);
        int left = f(i, j-1 , grid, dp);
        
        return dp[i][j] = min(up, left) + grid[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        // return f(m-1, n-1, grid, dp);
        
        vector<vector<int>> dp(m+1, vector<int> (n+1, INT_MAX));
        
        //basecase
        dp[0][0] = grid[0][0];
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == 0 && j == 0){
                    dp[0][0] = grid[0][0];
                }
                else{
                    int up = INT_MAX;
                    int left = INT_MAX;
                    
                    if( i >= 1){
                        up = dp[i-1][j];
                    }
                    
                    if(j >= 1){
                        left = dp[i][j-1];
                    }
                    
                    dp[i][j] = min(up, left) + grid[i][j];
                }
            }
        }
        
        return dp[m-1][n-1];
        
        
    }
};