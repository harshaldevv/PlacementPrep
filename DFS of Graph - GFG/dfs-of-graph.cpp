// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    void dfsHelper(vector<int> adj[], int i, vector<bool> &isVis, vector<int> &path){
        path.push_back(i);
        isVis[i] = true;
        
        // cout << " jere " << endl;
        
        for(auto nextVertex : adj[i]){
            if(!isVis[nextVertex]){
                // cout << "inside" << endl;
                dfsHelper(adj, nextVertex, isVis, path);
            }
        }
        return ;
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        vector<int> dfsPath;
        
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                dfsHelper(adj, i, visited, dfsPath);
            }
        }
        return dfsPath;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends