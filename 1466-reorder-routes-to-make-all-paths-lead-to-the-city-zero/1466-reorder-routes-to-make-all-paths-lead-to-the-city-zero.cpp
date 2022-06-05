class Solution {
public:
    
    void dfs_old(int curr, vector<vector<pair<int,bool>>> &adjList, int n, vector<bool> &vis, int &ans){
        if(vis[curr]){
            return;
        }
        
        vis[curr] = true;
        
        for(auto x : adjList[curr]){
            if(!vis[x.first]){
                // cout << "x.first = " << x.first <<endl;
                dfs_old(x.first, adjList, n, vis, ans);
                if(x.second == true){
                    // cout << "here" << endl;
                    ans++;
                }
            }
        }
        
        return ;
    }
    
    void dfs(int curr, vector<vector<int>> &adjlist, vector<bool> &vis, int &ans){
        if(vis[curr]){
            return;
        }
        
        vis[curr] = true;
        for(auto x :  adjlist[curr]){
            if(!vis[abs(x)]){
                dfs(abs(x), adjlist, vis, ans);
                if(x > 0){
                    ans++;
                }
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        
//         // make graph (adjList)
//         vector<vector<int>> adjList(n);
//         for(auto x :connections){
//             int u = x[0];
//             int v = x[1];
//             adjList[u].push_back(v);
//             adjList[v].push_back(-u);
//         }
//         vector<bool> vis(n, false);
//         int ans = 0;
//         dfs(0, adjList, vis, ans);
//         return ans;
        
        
        //adjList
        vector<vector<pair<int, bool>>> adjList(n);
        
        for(auto x : connections){
            int u = x[0];
            int v = x[1];

            adjList[u].push_back({v, true}); // true represents that this edges needs to be reversed
            adjList[v].push_back({u, false}); 
        }
        
        vector<bool> vis(n, false);
        int ans = 0;
        dfs_old(0, adjList, n, vis, ans);
        
        return ans;
        
        
        
    }
};