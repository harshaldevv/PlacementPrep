class Solution {
public:
    bool visited[300+1][300+1];
    
    bool isvalid(int i, int j, int m ,int n){
        return i >=0 && i < m && j >= 0 && j < n;
    }
    
    void dfs(vector<vector<char>> &grid, int &i, int &j, int &m , int &n){
        if(!isvalid(i,j, m,n)){
            return ;
        }
        
        // visited[i][j] = true;
        vector<int> dir{-1,0,1,0,-1};
        
        for(int k = 0 ; k < 4 ; k++){
            int newX = i + dir[k];
            int newY = j + dir[k+1];
            
            if( isvalid(newX, newY, m, n) && !visited[newX][newY] && grid[newX][newY] == '1') {
                visited[newX][newY] = true;
                dfs(grid, newX, newY, m,n);
            }
        }
        return ;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        memset(visited, 0, sizeof(visited));
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    visited[i][j] = true;
                    dfs(grid, i, j, m ,n);
                    ans++;
                }
            }
        }
        
        return ans;
        
    }
};