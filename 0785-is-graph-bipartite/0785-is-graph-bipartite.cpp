class Solution {
public:
    bool bipar(int curr, int par, vector<int> &color, vector<vector<int>> &graph){
        if(color[curr] == -1){
            color[curr] = 1;
        }
        
        for(auto &next : graph[curr]){
            if(color[next] == -1){
                //unvisited
                int colorToBe = 1 - color[curr];
                color[next] = colorToBe;
                if(!bipar(next, curr, color, graph)){
                    return false;
                }
            }
            else if(color[next] == color[curr]){
                return false;
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<int> color(n+1, -1);
        
        for(int i = 0 ; i < n ; i++){
            if(color[i] == -1){
                if(!bipar(i, -1, color, graph)){
                    return false;
                }
            }
        }
        
        return true;
        
    }
};