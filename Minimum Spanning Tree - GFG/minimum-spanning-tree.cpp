//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        int sum = 0;
        vector<bool> vis(V, false);
        vector<vector<int>> MST;
        
        pq.push({0,0, -1}); // wt, node, parent
        // parent is only needed incase you wish to know the MST
        // agar bas mst ka weight ka sum chahiye toh bas "wt, node" lete
        
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int wt = front[0];
            int currnode = front[1];
            int parent = front[2];
            
            if(vis[currnode]){
                continue;
            }
            
            vis[currnode] = true;
            sum += wt;
            MST.push_back({currnode, parent});
            
            for(auto &next : adj[currnode]){
                int nextNode = next[0];
                int edgeWt = next[1];
                if(!vis[nextNode]){
                    pq.push({edgeWt, nextNode, currnode});
                }
            }
        }
        
        
        return sum;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends