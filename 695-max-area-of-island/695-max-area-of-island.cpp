class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        
        if(i < 0 || j < 0 || i >= m || j>= n){
            return 0;
        }
        
        if(grid[i][j] != 1){
            return 0;
        }
        
        grid[i][j] = 2; 
        
        int up = dfs(grid, i-1, j);
        int down = dfs(grid, i+1, j);
        int left = dfs(grid, i, j-1);
        int right = dfs(grid, i, j+1);
        
        return 1 + up + down + left + right ; 
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        
        // use dfs
        int maxarea = 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    int area = dfs(grid, i, j);
                    maxarea = max(maxarea, area);
                }
            }
        }
        
        return maxarea;
        
        
    }
};