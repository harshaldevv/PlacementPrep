class Solution {
public:
    
    bool dfs(vector<vector<int>> &grid, int i, int j){
        if(i <0  || j < 0 || i >= grid.size() || j>= grid[0].size() ){
            return false ;
        }
        if(grid[i][j] != 0){
            return true; // either land or already visited
        }
        
        grid[i][j] = 2; // marking land as viisted
        
        bool top = dfs(grid, i-1, j); 
        bool down = dfs(grid, i+1, j);
        bool left = dfs(grid, i, j-1);
        bool right = dfs(grid, i, j+1);
        
        return top && down && left && right;
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        int count = 0;
        
        for(int i = 0 ; i < grid.size()  ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 0){
                    if(dfs(grid, i, j)){
                        //cout << " i , j = " << i << " , " << j << endl;
                        count++;
                    }
                    
                }
            }
        }
        
        return count;
        
    }
};