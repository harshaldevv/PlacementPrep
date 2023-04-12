class Solution {
public:
    void dfs(int src, int tx, vector<vector<int>> &grid, vector<bool> &vis){
        if(vis[src]){
            return ;
        }
        
        vis[src] = true;
        
        for(auto &p : grid[src]){
            if(!vis[p]){
                dfs(p, tx, grid, vis);
            }
        }
        
        return ;
    }
    bool canVisitAllRooms(vector<vector<int>>& grid) {
        
        
        int n = grid.size();
        
        vector<bool> vis(n, false);
        
        dfs(0, n-1, grid, vis);
        
        for(int i = 0 ; i < n ; i++){
            if(vis[i] == false){
                return false;
            }
        }
        
        return true;
        
    }
};