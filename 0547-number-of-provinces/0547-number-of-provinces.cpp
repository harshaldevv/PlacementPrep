class Solution {
public:
    void dfs(int src, vector<vector<int>> &adjList, vector<bool> &vis){
        if(vis[src]){
            return ;
        }
        
        vis[src] = true;
        for(auto &p : adjList[src]){
            if(!vis[p]){
                dfs(p, adjList, vis);
            }
        }
        
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<vector<int>> adjList(n+1);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(isConnected[i][j] == 1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int ans = 0;
        
        vector<bool> vis(n, false);
        
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                dfs(i, adjList, vis);
                ans++;
            }
        }
        
        return ans;
        
    }
};