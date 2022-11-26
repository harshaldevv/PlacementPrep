class Solution {
public:
    bool dfs(int &curr, vector<bool> &vis, vector<bool> &dfsvis, vector<int> adjList[]){
        vis[curr] = true;
        dfsvis[curr] = true;
        
        for(auto &next : adjList[curr]){
            if(!vis[next]){
                if(dfs(next, vis, dfsvis, adjList)){
                    return true;
                }
            }
            else if(dfsvis[next]){
                return true;
            }
        }
        
        dfsvis[curr] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // check if cycle exists -> if yes, return true else false;
        
        int n = numCourses;
        
        vector<int> adjList[n];
        for(int i = 0 ; i < prerequisites.size(); i++ ){
            int pehle = prerequisites[i][1];
            int baadme = prerequisites[i][0];
            
            adjList[pehle].push_back(baadme);
        }
        
        
        vector<bool> vis(n, false);
        vector<bool> dfsvis(n, false);
        
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                if(dfs(i, vis, dfsvis, adjList)){
                    //cycle detection via DFS
                    return false;
                }
            }
        }
        
        return true;
        
        
        
    }
};