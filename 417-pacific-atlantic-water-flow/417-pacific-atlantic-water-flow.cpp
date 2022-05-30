class Solution {
public:
    vector<vector<bool>> pac;
    vector<vector<bool>> alt;
    
    bool isValid(int i, int j, vector<vector<int>> &grid){
        if(i< 0 || j < 0 || i >= grid.size() || j>= grid[0].size()){
            return false;
        }
        return true;
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& ocean, int i, int j){
        if(!isValid( i, j, grid) || ocean[i][j]){
            return; // out of bound coordinates
        }
        ocean[i][j] = true;
        
        int dir[] = {1,0,-1,0,1};
        
        for(int k = 0 ; k < 4 ; k++){
            int newx = i + dir[k];
            int newy = j + dir[k+1];
            
            if(isValid(newx, newy, grid) && ocean[newx][newy] != true && grid[newx][newy] >= grid[i][j]){
                dfs(grid, ocean, newx, newy);
            }
        }
        return ;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pac (m, vector<bool>(n, false));
        vector<vector<bool>> alt (m, vector<bool>(n, false));
        
        for(int i = 0 ; i < m ; i++){
            dfs(heights, pac, i,0);
            dfs(heights, alt, i, n-1);
        }
        
        for(int j = 0 ; j < n ; j++){
            dfs(heights, pac, 0, j);
            dfs(heights, alt, m-1, j);
        }
        
        vector<vector<int>> ans;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(pac[i][j] && alt[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
        
        
    }
};