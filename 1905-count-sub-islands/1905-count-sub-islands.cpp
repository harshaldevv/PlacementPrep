class Solution {
public:
    bool add;
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        if(i < 0 || j < 0 || i >= grid2.size() || j>= grid2[0].size()){
            return ;
        }
        if(grid2[i][j] != 1){
            // either water or already visited;
            return ;
        }
        if(grid1[i][j] == 0){
            // useless piece of island
            add = false;
        }
        
        grid2[i][j] = 2;
        
        // dfs(grid1, grid2, i+1, j);
        // dfs(grid1, grid2, i, j-1);
        // dfs(grid1, grid2, i-1, j);
        // dfs(grid1, grid2, i, j+1);
        
        int dir[] = {1, 0, -1, 0, 1};
        for(int k = 0 ; k <4 ; k++){
            dfs(grid1, grid2, i +dir[k], j + dir[k+1]);
        }
        return ;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int m = grid2.size();
        int n = grid2[0].size();
        
        int count = 0;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid2[i][j] == 1){
                    add = true;
                    dfs(grid1, grid2, i, j);
                    if(add){
                        count++;
                    }
                }
            }
        }
        
        return count;
        
    }
};