class Solution {
public:
    bool isBipartiteHelper(int currVertex, vector<vector<int>> &adjList, vector<int> &color){
        
        cout << "color of curr = " << color[currVertex] << endl;
        
        if(color[currVertex] == -1){ 
            color[currVertex] = 1;
        }
        
        cout << "color of curr  (after if) = " << color[currVertex] << endl;
        
        for(auto nextVertex : adjList[currVertex]){
            if(color[currVertex] == color[nextVertex]){
                cout << "curr vertex --> " << currVertex << endl;
                cout << "nextVertex nextVertex --> " << nextVertex << endl;
                cout << "color curr vertex -> " << color[currVertex]  << endl;
                cout << "color nextVertex -> " << color[nextVertex]  << endl;
                
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