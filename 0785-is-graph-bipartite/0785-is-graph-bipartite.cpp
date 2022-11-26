class Solution {
public:
    
    bool biparatite(int curr, vector<vector<int>> &graph, vector<int> &color){
        
        if(color[curr] == -1){
            color[curr] = 1;
        }
        
        for(auto &next : graph[curr]){
            if(color[next] == -1){
                color[next] = 1 - color[curr];
                if(!biparatite(next, graph, color)){
                    return false;
                }
            }
            else if(color[next] == color[curr] ){
                return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<int> color(n, -1);
        
        //DFS method. next will do by BFS way
        
        for(int i = 0 ; i < n ; i++){
            if(color[i] == -1){
                if(!biparatite(i, graph, color)){
                    return false; 
                }
            }
        }
        
        return true;
        
    }
};