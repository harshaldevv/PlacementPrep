class Solution {
public:
    void dfs(vector<vector<int>> &grid, int i , int j){
        if( i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
            // invalid coordinates
            return ;
        }
        
        if(grid[i][j] != 0){
            return; // either land or already visited,
        }
        
        grid[i][j]  = 2; // marking visited
        
        
        int dx[] = {1,0,-1,0,1}; // hmmm smart
        
        for(int k = 0 ; k < 4 ; k++){
            dfs(grid, i + dx[k], j + dx[k+1]);
        }
     
        return ;
        
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cout << grid[i][j] << " " ;
            }
            cout << endl;
        }
        
        // sare boundaries pe jao and sare 0 connected (boundary) walo ko "water or visited" bana do
        for(int i = 0 ; i < n ; i++){
            if(grid[i][0] == 0){
                dfs(grid, i, 0);
                // dfs(grid, )
            }
            if(grid[i][m -1] == 0){
                dfs(grid, i , m-1);
            }
        }
        
        for(int j = 0 ; j < m ; j++ ){
            if(grid[0][j] == 0){
                dfs(grid, 0, j);
            }
            if(grid[n-1][j] == 0){
                dfs(grid, n-1, j);
            }
        }
        // printing matrix
        cout << endl;
        cout << endl;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cout << grid[i][j] << " " ;
            }
            cout << endl;
        }
        
        // uske baad do normal dfs 
        // count no of islands basically
        
        int count = 0;
        
        for(int i = 0 ; i< grid.size();i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 0){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
        
        
    }
};