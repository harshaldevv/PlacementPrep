class Solution {
    void dfs(vector<vector<char>>& grid, int i, int j){
        int maxRows = grid.size();
        int maxCols = grid[0].size();
        
        if(i < 0 || j < 0 || i >= maxRows || j >= maxCols){
            return ;
        }
        else if(grid[i][j] != '1'){
            return ; // either water or land already visited
        }
        
        grid[i][j] = '2'; // marking the piece of land as VISITED
        
        // left, right, top, bottom dfs calls
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        
        return ;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        long long island = 0;
        
        for(int i = 0 ;i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(grid[i][j] == '1'){ 
                    // if found a piece of land, do dfs 
                    // and other neighbbouring piece of land(s)
                    // and make an island if possible
                    
                    dfs(grid, i, j);
                    island++;
                }
                
            }
        }
        
        return island;
        
        
    }
};