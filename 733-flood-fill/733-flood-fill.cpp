class Solution {
public:
    bool isvalid(vector<vector<int>> &grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        
        if( i < 0 || j < 0 || i>= m || j >= n){
            return false;
        }
        
        return true;
        
    }
    void dfs(vector<vector<int>> &grid, int i, int j, int org, int color){
        if(!isvalid(grid, i, j)){
            return ;
        }
        
        if(grid[i][j] != org){
            return ;
        }
        
        // else grid[i][j] = org , therefore we change its color to "color"
        grid[i][j] = color;
        
        int dir[5] = {-1,0,1,0,-1};
        
        for(int k = 0 ; k < 4 ; k++){
            int newx = i + dir[k];
            int newy = j + dir[k+1];
            
            dfs(grid, newx, newy, org, color);
        }
        
        return ;
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color){
            return image; 
            // learned this from example 2.
            // If startingRow and startingColumn cell is already filled
            // with the color COLOR, then no changes are to be made to the image
        }
        
        int originalColor = image[sr][sc];
        dfs(image, sr, sc, originalColor, color);
        
        
        return image;
    }
};