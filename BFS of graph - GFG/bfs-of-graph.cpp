// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    void bfs(vector<int> adj[], int currvertex, vector<bool> &vis, vector<int> &path){
        vis[currvertex] = true;
        
        
        queue<int> q;
        q.push(currvertex);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            path.push_back(front);
            for(auto nexVertex : adj[front]){
                if(!vis[nexVertex]){
                    q.push(nexVertex);
                    vis[nexVertex] = true;
                }
            }
        }
    }
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V, false);
        
        vector<int> path;
        // for(int i = 0 ; i < V ; i++){
        //     if(!vis[i]){
                bfs(adj, 0, vis, path);
        //     }
        // }
        return path;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends