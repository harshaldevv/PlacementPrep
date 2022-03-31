class Solution {
public:
    int dp[200+1][200+1];
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        // redo this ques, feeling nahi aayi.
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        int health = 0;
        // health =  helper(0, 0, dungeon);
        
        
        memset(dp, -1, sizeof(dp));
        health = helper2(0,0, dungeon);
        return health;
        
    }
    
    int helper(int row, int col, vector<vector<int>> &grid){
        if(row >= grid.size() || col >= grid[0].size()){
            return INT_MAX;
        }
        
        if(row == grid.size() -1 && col == grid[0].size()-1){
            if(grid[row][col] < 0){
                return 1 + abs(grid[row][col]);
            }
            else{
                //grid[row][col] >= 0
                return 1;
            }
        }
        
        int health = min(helper(row+1, col, grid), helper(row, col+1, grid)) - grid[row][col];
        
        if(health <= 0){
            health = 1;
        }
        
        return health;
        
    }
    
    int helper2(int row, int col, vector<vector<int>> &grid){
        if(row >= grid.size() || col >= grid[0].size()){
            dp[row][col] = INT_MAX;
            return INT_MAX;
        }
        
        if(row == grid.size() -1 && col == grid[0].size() -1){
            if(grid[row][col] < 0){
                dp[row][col] = 1 + abs(grid[row][col]);
                return 1 + abs(grid[row][col]);
            }
            else{
                dp[row][col] =1;
                return 1;
            }
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        
        int health = min(helper2(row+1, col, grid), helper2(row, col+1, grid)) - grid[row][col];
        if(health <=0){
            health = 1;
        }
        
        dp[row][col] = health;
        
        
        return health;
    }
};