class Solution {
public:
    
    bool cycleDetected(int currvertex, vector<vector<int>> &adjList, vector<bool> &visited, vector<bool> &dfsvisited){
        
       // detect cycle in a directed graph
        
        
        visited[currvertex] = true;
        dfsvisited[currvertex] = true;
        
        for(auto nextvertex : adjList[currvertex]){
            if(!visited[nextvertex]){
                if(cycleDetected(nextvertex, adjList, visited, dfsvisited)){
                    return true;
                }
            }
            else if(dfsvisited[nextvertex]){
                //cycle detected confirmed
                
                // visited[nextVertex] == dfsVisited[nextVertex] --> this condition met when cycle is detected
                // visited hai and dfsvisit me bhi visited hai
                // matlab cycle hai pakka
                
                return true;
            }
        }
        
        dfsvisited[currvertex] = false;
        
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // directed graph 
        // detect cycle --> if cycle detected return false
        // else return true
        
        
        //cycle detection --> either by BFS or DFS --> learn both
        
        int n = numCourses;
        
        vector<vector<int>> adjList(n);
        
        for(auto &x : prerequisites){
            int u = x[1];
            int v = x[0];
            
            adjList[u].push_back(v);
        }
        
        vector<bool > visited(n, false);
        vector<bool> dfsVisited(n, false);
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                if(cycleDetected(i, adjList, visited, dfsVisited)){
                    return false;
                }
            }
        }
        
        return true;
        
    }
};