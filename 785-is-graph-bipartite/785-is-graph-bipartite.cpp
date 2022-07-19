class Solution {
public:
    
    bool isBipartiteGraph(vector<vector<int>> &graph, int currvertex, vector<int> &color){
        
        if(color[currvertex] == -1){
            color[currvertex] = 1;
        }
        
        for(auto nextvertex : graph[currvertex]){
            if(color[nextvertex] == color[currvertex]){
                // neighbour (nextvertex) has same color as the currvertex
                // not a bipartite graph
                return false;
            }
            else if(color[nextvertex] == -1){
                color[nextvertex] = 1 - color[currvertex];
                if(!isBipartiteGraph(graph, nextvertex, color)){
                    return false;
                }
            }
        }
        
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n, -1);
        
        for(int i = 0 ; i < n ; i++){
            if(!isBipartiteGraph(graph, i, color)){
                return false;
            }
        }
        
        return true;
    }
};