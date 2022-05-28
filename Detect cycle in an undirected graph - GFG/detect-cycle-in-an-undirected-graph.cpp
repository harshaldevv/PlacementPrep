// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  bool dfs(vector<int> adj[], int i, int p, vector<bool> &vis){
      
      vis[i] = true;
      
      for(auto x : adj[i]){
          if(x == p){
              continue;
          }
          else if(!vis[x]){
              if(dfs(adj, x, i, vis)){
                  return true;
              }
          }
          else{
              // cycle detected 
              return true;
          }
      }
      
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V, false);
        
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                if(dfs(adj, i, -1, vis)){
                    return true;
                }
            }
        }
        return false;
    }
    
    
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends