class Solution {
public:
    void dfs(int i, vector<vector<int>> &rooms, vector<bool> &vis){
        
        if(vis[i]){ // if already visited
            return;
        }
        
        vis[i] = true;
        
        for(auto x : rooms[i]){
            if(!vis[x]){
                dfs(x, rooms, vis);
            }
            
        }
        
        return ;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        vector<bool> vis(n,false);
    
        dfs(0, rooms, vis);
        
        for(int i = 0 ; i < n ; i++){
            // cout << vis[i] << " , " ;
            if(!vis[i]){
                return false;
            }
        }
        
        return true;
        
    }
};