class Solution {
public:
    bool isvalid(int &i, int &j, int &m, int &n){
        if(i < 0 || i >= m || j < 0 || j>= n){
            return false;
        }
        return true;
    }
    
    int dfs(vector<vector<int>> &grid, int i, int j, int &m, int &n){
        if(!isvalid(i,j,m,n)){
            return 0;
        }
        
        if(grid[i][j] != 1){
            return 0;
        }
        
        grid[i][j] = 2;
        
        vector<int> dir{-1,0,1,0,-1};
        
        int a1 = dfs(grid, i-1, j, m, n);
        int a2 = dfs(grid, i+1, j, m, n);
        int a3 = dfs(grid, i, j-1, m, n);
        int a4 = dfs(grid, i, j+1, m, n);
        
        return a1+a2+a3+a4 +1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0 ; i < m ; i ++){
            for(int j =0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    int area = dfs(grid, i, j, m,n);
                    ans = max(area, ans);
                }
            }
        }
        
        return ans;
        
    }
};