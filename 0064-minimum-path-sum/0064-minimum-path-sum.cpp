class Solution {
public:
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i == 0 && j == 0){
            return  grid[0][0];
        }
        else if(i < 0 || j < 0){
            return INT_MAX; // IMPORTANT
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        return dp[i][j] =  grid[i][j] + min( f(i-1, j, grid, dp), f(i, j-1, grid, dp)) ;
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        return f(m-1, n-1, grid, dp);
        
        // tabulization
        
        
        
    }
};