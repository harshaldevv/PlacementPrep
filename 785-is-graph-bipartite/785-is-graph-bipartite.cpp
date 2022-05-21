class Solution {
public:
    bool isBipartiteHelper(int currVertex, vector<vector<int>> &adjList, vector<int> &color){
        
        
        
        if(color[currVertex] == -1){ 
            color[currVertex] = 1;
        }
        
        
        
        for(auto nextVertex : adjList[currVertex]){
            if(color[currVertex] == color[nextVertex]){
                return false;
            }
            else if(color[nextVertex] == -1){
                color[nextVertex] = 1 - color[currVertex];
                if(!isBipartiteHelper(nextVertex, adjList, color)){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {

        int vertices = graph.size();        
        
        vector<int> color(vertices, -1);
        // -1 --> unvisited uncolored
        // 0 --> red
        // 1 --> blue
        
        for(int i = 0 ; i < vertices ; i++){
            if(color[i] == -1){
                if(!isBipartiteHelper(i, graph, color)){
                    return false;
                }
            }
        }
        
        return true;
        
    }
};