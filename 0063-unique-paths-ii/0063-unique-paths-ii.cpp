class Solution {
public:
    int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i < 0 || j < 0){
            return 0;
        }
        if(grid[i][j] == 1){
            return dp[i][j] = 0;
        }
        
        if(i == 0 && j == 0 && grid[i][j] == 0){
            return dp[i][j] = 1;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = helper(i-1, j, grid, dp) + helper(i, j-1, grid, dp);
        
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[m-1][n-1] == 1){
            return 0;
        }
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return helper(m-1, n-1, grid, dp);
        
    }
};