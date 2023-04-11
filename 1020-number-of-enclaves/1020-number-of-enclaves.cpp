class Solution {
public:
    bool isvalid(int i, int j, int m, int n){
        if(i < 0 || j < 0 || i >= m || j >= n){
            return false;
        }
        return true;
    }
    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &vis){
        if(!isvalid(x,y, grid.size(), grid[0].size())){
            return ;
        }
        
        if(vis[x][y]){
            return ;
        }
        
        vis[x][y] = true;
        
        vector<int> dir{-1,0,1,0,-1};
        
        for(int i = 0 ; i < 4 ; i++){
            int newx = x + dir[i];
            int newy = y + dir[i+1];
            
            if(isvalid(newx, newy, grid.size(), grid[0].size()) && grid[newx][newy] == 1 && !vis[newx][newy]){
                dfs(newx, newy, grid, vis);
            }
        }
        
        return ;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        // border wale 1s se dfs
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == 0 || i == m-1 || j == 0 || j == n-1){
                    if(grid[i][j] == 1 && !vis[i][j]){
                        dfs(i,j, grid, vis);
                    }
                }
            }
        }
        
        
        int ans = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    ans++;
                }
            }
        }
        
        return ans;
        
        
        
    }
};