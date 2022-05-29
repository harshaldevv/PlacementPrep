class Solution {
public:

    void dfs(vector<vector<int>> &grid, int i, int j){
        if( i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
            return;
        }
        if(grid[i][j] != 1){
            return ; // either visited or sea
        }
        
        grid[i][j] = 2;
        
        int dir[] = {1,0,-1,0,1}; // dir array
        
        for(int k = 0 ; k < 4 ; k++){
            dfs(grid, i + dir[k], j + dir[k+1]);
        }
        
        return ;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        

        int m = grid.size();
        int n = grid[0].size();
        
        // we fill/visit all those cells with 1 which are at boundary or
        // are somehow connected to a boundary cell which has value = 1
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if( i== 0 || j == 0 || i == m-1 || j == n-1){
                    dfs(grid, i, j);
                }
            }
        }
        
        // now that we've visited and marked those cells,
        //we'll just count the remaining number of land with cell value = 1
        // koi dfs nahi lagana yahan
        
        // had it been ki count the number of components, toh dfs lagata 
        // like in --> https://leetcode.com/submissions/detail/708895770/
            
        int count = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    count++;
                    
                }
            }
        }
        return count;
        
    }
};