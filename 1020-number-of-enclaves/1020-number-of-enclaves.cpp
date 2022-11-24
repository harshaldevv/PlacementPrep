class Solution {
public:
    bool isValid(int &i, int &j, int &m, int &n){
        return i >=0 && i < m && j >=0 && j < n;
    }
    void doDFS(vector<vector<int>> &grid, int i, int j, int &m, int &n){
        if(!isValid(i,j,m,n) || grid[i][j] != 1){
            // either not valid coordinates or visited already
            return ;
        }
        
        grid[i][j] = 2;
        
        vector<int> dir{1,0,-1,0,1};
        
        for(int k =0 ; k <4 ; k++){
            doDFS(grid, i + dir[k], j + dir[k+1], m,n);
        }
        
        return ;
        
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        //mark visited to all the 1s that are at the boundary and those 1s that are connected to such
        // 1s (jo boundary pe 1s hai)
        
        int ans = 0;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == 0 || i== m-1 || j == 0 || j == n-1){
                    if(grid[i][j] == 1){
                        doDFS(grid, i, j, m, n);
                    }
                }
            }
        }
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j <n ; j++){
                if(grid[i][j] == 1){
                    ans++;
                }
            }
        }
        
        return ans;
        
    }
};