class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i, int j){
        if( i <0 || j <0 || i >= grid.size() || j >= grid[0].size()){
            return 0;
        }
        if(grid[i][j] != 1){
            return 0;
        }
        
        grid[i][j] = 2; // marked visited
        
        int a = dfs(grid, i, j-1);
        int b = dfs(grid, i, j+1);
        int c = dfs(grid, i-1, j);
        int d = dfs(grid, i+1, j);
        
        return 1 + a+b+c+d;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxArea = 0;
        
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j  = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1){
                    
                    int area = dfs(grid, i, j);
                    //cout << " area = " << area << endl;
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
        
    }
};