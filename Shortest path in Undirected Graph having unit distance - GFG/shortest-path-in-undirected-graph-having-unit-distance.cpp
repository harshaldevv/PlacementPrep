//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> dist(N, 1000);
        //make graph
        vector<int> adjList[N];
        for(int i = 0 ; i < M ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                int u = q.front();
                q.pop();
                for(auto next : adjList[u]){
                    if(dist[next]  == 1000){
                        dist[next] = min( dist[u] +1, dist[next]);
                        q.push(next);    
                    }
                }
            }
        }
        
        for(int i = 0 ; i < dist.size() ; i++){
            if(dist[i] == 1000 ){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends