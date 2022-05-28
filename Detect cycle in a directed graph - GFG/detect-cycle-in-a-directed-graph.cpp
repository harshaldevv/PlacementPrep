// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  bool isCycleHelper(int i, vector<int> adj[], vector<int> &vis, vector<int> &dfsvis){
      vis[i] = 1;
      dfsvis[i] = 1;
      
      for(auto x : adj[i]){
          if(!vis[x]){
              if(isCycleHelper(x, adj, vis, dfsvis)){
                  return true;
              }
          }
          else if (dfsvis[x]){
              // already visited hai
              // check  if dfsvis is also true
              return true;
          }
      }
      
      dfsvis[i] = 0;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V, 0);
        vector<int> dfsvisit(V, 0);
        
        for(int i = 0 ; i< V ; i++){
            if(!visited[i]){
                if(isCycleHelper(i, adj, visited, dfsvisit)){
                    return true;
                }
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends