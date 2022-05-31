class Solution {
public:
    void dfs(int currRoom, vector<vector<int>>& rooms, vector<bool> &vis ){
        
        vis[currRoom ] = true;
        
        for(auto nextRoom : rooms[currRoom]){
            if(!vis[nextRoom]){
                dfs(nextRoom, rooms, vis);
            }
            
        }
        return ;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(0, rooms, vis);
        
        
        for(int i = 0 ; i < n ; i++){
            if(vis[i] == false){
                return false;
            }
        }
        
        return true;
        
    }
};