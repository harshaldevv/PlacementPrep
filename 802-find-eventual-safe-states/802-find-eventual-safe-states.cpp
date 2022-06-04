class Solution {
public:
    // reference -> https://www.youtube.com/watch?v=4ymVOCiQBtw
    bool DFS(int currvertex, vector<vector<int>>& graph, vector<bool> &vis, vector<bool> &dfsvis, vector<bool> &presentInCycle){
        
        vis[currvertex] = true;
        dfsvis[currvertex] = true;
        
        for(auto nextvertex : graph[currvertex]){
            if(!vis[nextvertex]){
                if(DFS(nextvertex, graph, vis, dfsvis, presentInCycle)){
                    presentInCycle[currvertex] = true;
                    return true;
                }
            }
            else if(dfsvis[nextvertex] == true && vis[nextvertex] == true){
                presentInCycle[currvertex] = true;
                return true;
            }
        }
        
        dfsvis[currvertex] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        // basically this ques is 
        // every vector in graph minus (vertices that are stuck in a cycle of a directed graph)
        
        // task 1 -> find all vertices that are stuck in a cycle
        
        int n = graph.size();
        
        vector<bool> vis(n, false);
        vector<bool> dfsvis(n, false);
        vector<bool> presentInCycle(n, false);
        
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                DFS(i, graph, vis, dfsvis, presentInCycle);
            }
        }
        
        // task 2 --> add all those add in our ans vector
        // which are not stuck in a loop
        
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            if(!presentInCycle[i]){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};