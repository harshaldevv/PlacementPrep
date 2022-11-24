class Solution {
public:
    bool isValid(int &i, int &j, int &m , int &n){
        return i >=0 && i < m && j >=0 && j < n;
    }
    void doDFS(vector<vector<int>> &grid, int i, int j, int &m , int &n){
        if(!isValid(i,j,m,n) || grid[i][j] != 0){
            return ;
        }
        
        grid[i][j] = 2;
        
        
        vector<int> dir{1,0,-1,0,1};
        
        for(int k = 0 ; k < 4 ; k++){
            doDFS(grid, i + dir[k], j + dir[k+1], m, n);
        }
        
        return ;
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // 0 = land
        // 1 = water
        
        //border wale 0s ko exclude karo abhi
        for(int i = 0 ; i < m ; i++){
            if(grid[i][0] == 0) {
                // left column 
                doDFS(grid, i, 0, m, n);
            }
        }
        
        for(int i = 0 ; i < m ; i++){
            if(grid[i][n-1] == 0) {
                 // right column
                doDFS(grid, i, n-1, m, n);
            }
        }
        
        for(int j = 0; j < n ; j++){
            if(grid[0][j] == 0 ){
                // first row 
                doDFS(grid, 0, j, m, n);
            }
        }
        
        for(int j = 0; j < n ; j++){
            if(grid[m-1][j] == 0 ){
                // last row
                doDFS(grid, m-1, j, m, n);
            }
        }
        
        int ans = 0;
        
        for(int i =0 ; i < m ; i++){
            for(int j = 0 ; j < n ;j++){
                if(grid[i][j]== 0){
                    doDFS(grid, i, j, m, n);
                    ans++;
                }
            }
        }
        
        return ans;
        
        
    }
};