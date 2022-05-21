class Solution {
public:
    
    bool isBipartite(int currvertex, vector<vector<int>> &adjList, vector<int> &color){
        if(color[currvertex] == -1){
            color[currvertex] = 1;
        }
        for(auto nextVertex : adjList[currvertex]){
            if(color[currvertex] == color[nextVertex]){
                return false;
            }
            else if(color[nextVertex]  == -1){
                color[nextVertex] = 1- color[currvertex];
                if(!isBipartite(nextVertex, adjList, color)){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // basically do bipartitie graph
        vector<vector<int>> adjList(n+1);
        // make adjList
        
        for(auto x : dislikes){
            int u = x[0];
            int v = x[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        
        vector<int> color(n+1, -1);
        
        for(int i = 1 ; i<= n ; i++){
            if(color[i] == -1){
                // univisited and uncolored
                if(!isBipartite(i, adjList, color)){
                    return false;
                }
            }
        }
        
        return true;
        
    }
};