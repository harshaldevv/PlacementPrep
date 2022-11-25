class Solution {
public:
    void dfs(vector<vector<int>> &rooms, int currvertex, int endvertex, vector<bool> &vis){
        for(auto &x : rooms[currvertex]){
            if(!vis[x]){
                vis[x] = true;
                dfs(rooms, x, endvertex, vis);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();
        vector<bool> vis(n, false);
        vis[0] = true;
        dfs(rooms, 0, n-1, vis);
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};