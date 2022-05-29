class Solution {
public:
    int ans = 0;
    void dfs(vector<vector<int>> &grid, int i, int j){
        if( i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
            return;
        }
        if(grid[i][j] != 1){
            return ; // either visited or sea
        }
        
        grid[i][j] = 2;
        ans++;
        
        int dx[] = {1,0,-1,0,1};
        
        for(int k = 0 ; k < 4 ; k++){
            dfs(grid, i + dx[k], j + dx[k+1]);
        }
        
        return ;
    }
    
    void dfs2(vector<vector<int>> &grid, int i, int j){
        if(i<0 || j < 0 || i>= grid.size() || j >= grid[0].size()){
            return ;
        }
        
        if(grid[i][j] != 1){
            return ;
        }
        
        grid[i][j] = 2;
        ans++;
        return ;
        
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        

        int m = grid.size();
        int n = grid[0].size();
        cout << " m =  " << m <<  endl;
        
//         // first col, last col
//         for(int i = 0 ; i < m ; i++){
//             if(grid[i][0] == 1){
//                 dfs(grid, i, 0);
//             }
//             if(grid[i][n-1] == 1){
//                 dfs(grid, i, m-1);
//             }
//         }
        
//         // top row, last row
//         for(int j = 0 ; j < n ; j++){
//             if(grid[0][j] == 1){
//                 dfs(grid, 0, j);
//             }
//             if(grid[m-1][j] == 1){
//                 dfs(grid, n-1, j);
//             }
//         }
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if( i== 0 || j == 0 || i == m-1 || j == n-1){
                    dfs(grid, i, j);
                }
            }
        }
        
        int count = 0;
        //ans = 0;
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