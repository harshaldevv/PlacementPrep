class Solution {
public:
    vector<int> dir{1,0,-1,0,1};
    bool isvalid(int i, int j, int m, int n){
        return i>=0 && i < m && j>=0 && j < n;
    }
    void dfs(int i, int j, vector<vector<char>>&grid,vector<vector<bool>>&vis, int &m, int &n){
        if(vis[i][j] == true){
            return ;
        }
        
        if(grid[i][j] != 'O'){
            return ;
        }
        
        vis[i][j] = true;
        
        for(int k = 0 ; k < 4 ; k++){
            int newx = i + dir[k];
            int newy = j + dir[k+1];
            
            if(isvalid(newx, newy, m,n) && !vis[newx][newy] && grid[newx][newy] == 'O'){
                dfs(newx, newy, grid, vis, m, n);
            }
        }
        
        return ;
        
    }
    void solve(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>  vis(m, vector<bool>(n, false));
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == 0 || j ==0 || i == m-1 || j == n-1){
                    dfs(i,j, grid, vis, m,n);
                }
            }
        }
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 'O' && !vis[i][j]){
                    grid[i][j] = 'X';
                }
            }
        }
        
        return ;
        
    }
};