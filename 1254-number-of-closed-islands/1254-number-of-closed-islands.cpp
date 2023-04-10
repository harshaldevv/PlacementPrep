class Solution {
public:
    bool isvalid(int i, int j, int m, int n){
        if(i <0 || j < 0 || i >= m || j >= n){
            return false;
        }
        return true;
    }
    
    void dfs(int x,int y,int m, int n, vector<vector<int>> &grid){
        if(!isvalid(x,y,m,n)){
            return ;
        }
        
        grid[x][y] = 2; // marking visited
        
        vector<int> dir{-1,0,1,0,-1};
        
        for(int i = 0 ; i < 4 ; i++){
            int newx = x + dir[i];
            int newy = y + dir[i+1];
            
            if(isvalid(newx, newy, m, n) && grid[newx][newy] == 0){
                dfs(newx, newy, m, n, grid);
            }
        }
        
        return ;
        
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        //all zero at boundary
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i==0 || j == 0 || i == m-1 || j == n-1){
                    if(grid[i][j] == 0){
                        // dfs krke mark out krdo
                        dfs(i,j, m, n, grid);
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0){
                    //
                    dfs(i,j,m,n, grid);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};