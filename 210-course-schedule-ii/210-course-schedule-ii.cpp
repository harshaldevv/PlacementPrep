class Solution {
public:
    bool cycleDetected(vector<vector<int>> &adj, int curr, vector<bool> &vis, vector<bool> &dfsvis){
        
        vis[curr] = true;
        dfsvis[curr] = true;
        
        for(auto nextvertex : adj[curr]){
            if(!vis[nextvertex]){
                if(cycleDetected(adj, nextvertex, vis, dfsvis)){
                    return true;
                }
            }
            else if(dfsvis[nextvertex]){
                // visited[nextvertex] true and dfsvisited[nextvertex] bhi true hai 
                // therefore same dfs visit me hi hume already visited node mil gyi
                return true;
                
            }
        }
        
        dfsvis[curr] = false;
        return false;
        
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        // dire
        vector<vector<int>> adjList(n);
        vector<int> indegree(n);
        
        for(auto &x : prerequisites){
            int u = x[1];
            int v = x[0];
                
            adjList[u].push_back(v);
            
            indegree[v]++;
                
        }
        
        // check if a cycle exists 
        // direted graph --> cycle --> dfs --> vis[], dfsvist
        
        vector<bool> vis(n, false);
        vector<bool> dfsvis(n, false);
        bool isCycle = false;
        for(int i = 0 ; i < n; i++){
            if(!vis[i]){
                if(cycleDetected(adjList, i, vis, dfsvis)){
                    isCycle = true;
                    break;
                }
            }
            
        }
        
        vector<int> ans;
        
        if(isCycle == true){
            // If it is impossible to finish all courses, return an empty array.
            // cout << "here " << endl;
            return ans;
        }
        
        // now find order
        //
        
        queue<int> q;
        
        for(int i = 0 ; i < indegree.size() ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        // now do topo sort to find the correct ordering 
        // use topo sort BFS (kahn's algo)
    
        
        vector<int> toposort;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            toposort.push_back(front);
            
            for(auto nextvertex : adjList[front]){
                indegree[nextvertex]--;
                
                if(indegree[nextvertex] == 0){
				    //push in queue
				    q.push(nextvertex);
                }
                
            }
        }
        
        
        return toposort;
        
            
        
    }
};