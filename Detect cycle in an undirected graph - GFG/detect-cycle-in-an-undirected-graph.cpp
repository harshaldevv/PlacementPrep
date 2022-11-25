//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool detect(int src, int par, vector<int> adj[], bool vis[]){
        
        if(vis[src]){
            return true; // cycle detected
        }
        
        vis[src] = true;
        
        for(auto &next : adj[src]){
            if(!vis[next]){
                if(detect(next, src, adj, vis)){
                    return true;
                }
            }
            else if(next != par){
                return true;
            }
        }
        
        return false;
        
        
        // queue<vector<int>> q;
        
        // q.push({src, -1});
        
        // while(!q.empty()){
        //     int sz = q.size();
        //     while(sz--){
        //         auto front = q.front();
        //         q.pop();
                
        //         int curr = front[0];
        //         int parent = front[1];
                
        //         for(auto &next : adj[curr]){
        //             if(!vis[next]){
        //                 vis[next] = true;
        //                 q.push({next, curr});
        //             }
        //             else if(next != parent){
        //                 return true;
        //             }
        //         }
        //     }
        // }
        
        // return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        bool vis[V];
        memset(vis, 0, sizeof(vis));
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                // if(detect(i, adj, vis)){
                //     return true;
                // }
                
                if(detect(i, -1, adj,vis)){
                    return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
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
}
// } Driver Code Ends