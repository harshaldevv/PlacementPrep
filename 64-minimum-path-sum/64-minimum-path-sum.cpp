class Solution {
public:
    int dp[200+1][200+1];
    int minPathSum(vector<vector<int>>& grid) {
        // return helper(grid.size()-1, grid[0].size()-1, grid);
        memset(dp, -1, sizeof(dp));
        return helper2(grid.size() -1, grid[0].size() -1, grid);
    }
    
    int helper2(int row, int col, vector<vector<int>> &grid){
        if(row == 0 && col == 0){
            return grid[row][col];
        }
        if(row < 0 || col < 0){
            return INT_MAX;
        }
        
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        
        dp[row][col] = grid[row][col] + min(helper2(row-1, col, grid) , helper2(row, col-1, grid));
        return dp[row][col];
        
        
    }
    
    int helper(int row, int col, vector<vector<int>> &grid){
        if(row == 0 && col == 0){
            return grid[row][col];
        }
        if(row <0 || col <0){
            return 101;
        }
        
        return grid[row][col] + min(helper(row-1, col, grid), helper(row, col-1, grid));
    }
};