class Solution {
public:
    
    bool dfs(vector<vector<int>> &graph, int curr, vector<bool> &vis, vector<bool> &dfsvis, vector<bool> &presentInCycle){
        vis[curr] = true;
        dfsvis[curr] = true;
        
        for(auto &next : graph[curr]){
            if(!vis[next]){
                if(dfs(graph, next, vis, dfsvis, presentInCycle)){
                    presentInCycle[curr] = true;
                    return true;
                }
            }
            else if(vis[next] && dfsvis[next]){
                presentInCycle[curr] = true;
                return true;
                
            }
        }
        
        dfsvis[curr] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> ans;
        
        //find those stuck in cycle -> everyone who is stuck in cycle, would never be in our safe node answer array
        //DIRECTED GRAPH hai ->therefore use cycle detection in directed graph
        
        vector<bool> vis(n, false);
        vector<bool> dfsvis(n, false);
        vector<bool> presentInCycle(n, false);
        
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                dfs(graph, i, vis, dfsvis, presentInCycle);
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            if(!presentInCycle[i]){
                ans.push_back(i);
            }
        }
        
        
        return ans;
    }
};