class Solution {
public:
    bool isvalid(int &i, int &j, int &m, int &n){
        return i >=0 && i < m && j >=0 && j < n;
    }
    
    void dfs(vector<vector<int>> &grid2, vector<vector<int>> &grid1, int i, int j, int &m, int &n, bool &something){
        
        if(!isvalid(i,j,m,n)){
            return ;
        }
        
        if(grid2[i][j] != 1){
            return ;
        }
        
        if(grid1[i][j] == 0){
            // useless piece
            //but we'll still have to continue our recursion
            something = false;
        }
        
        grid2[i][j] = 2;
        
        
        vector<int> dir{1,0,-1,0,1};
        
        for(int k = 0 ; k < 4 ; k++){
            dfs(grid2, grid1, i + dir[k], j + dir[k+1], m, n, something);
        }
        
        
        return ;
        
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int ans = 0;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid2[i][j] == 1){
                    bool something = true;
                    dfs(grid2, grid1, i, j, m, n, something);
                    if(something){
                        ans++;
                    }
                    
                }
            }
        }
        
        return ans;
    }
};