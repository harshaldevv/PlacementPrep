class Solution {
public:
    
    void dfs(int i, vector<vector<int>> &adjList, vector<bool> &vis){
        if(vis[i]){
            return ;
        }
        
        vis[i] = true;
        
        for(auto x : adjList[i]){
            dfs(x, adjList, vis);
        }
        
        return ;
        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        // count number of connected components
        int count = 0;
        
        if(connections.size() < n-1){
            return -1;
        }
        
        vector<bool> vis(n, false);
        
        // making adjList
        vector<vector<int>> adjList(n);
        for(auto x : connections){
            auto a = x[0];
            auto b = x[1];
            
            adjList[a].push_back(b);
            adjList[b].push_back(a);
            
        }
        
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                dfs(i, adjList, vis);
                count++;
            }
        }
        
        return count -1;
        
    }
};