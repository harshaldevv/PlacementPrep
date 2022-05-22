class Solution {
    void dfs(char[][] grid, int i, int j ){
        int totalRows = grid.length;
        int totalCols = grid[0].length;
        
        if(i<0 || j <0 || i >= totalRows || j >= totalCols ){
            return ;
        }
        else if(grid[i][j] != '1'){
            return;  // either water or land already visited 
        }
        
        grid[i][j] = '2'; // marking land as visited
        
        
        // left, right, top, down
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        
        return ;
        
    }
    public int numIslands(char[][] grid) {
        // using dfs
        int n = grid.length;
        int m = grid[0].length;
        
        int  island = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    island++;
                }
            }
        }
        
        
        return island;
    }
}