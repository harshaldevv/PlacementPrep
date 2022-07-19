class Solution {
public:
    
    bool isvalid(int i, int j, int m, int n){
        if(i < 0 || j < 0 || i >= m || j >= n){
            return false;
        }
        
        return true;
    }
    
    void doDFS(vector<vector<char>> &grid, int i , int j){
        int m = grid.size();
        int n = grid[0].size();
        
        if(!isvalid(i,j,m,n)){
            return ;
        }
        
        if(grid[i][j] !=  '1'){
            // already visited ('2') or water ('0')
            return ;
        }
        
        grid[i][j] = '2';
        
        int dir[5] = {1,0,-1,0,1};
        
        for(int k = 0 ; k < 4 ; k++){
            int newx = i + dir[k];
            int newy = j + dir[k+1];
            doDFS(grid, newx, newy);
        }
        
        return ;
           
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == '1'){
                    doDFS(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
        
    }
};