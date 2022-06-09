class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        //undirected graph
        vector<vector<int>> adjList(n);
        
        for(auto x : roads){
            int u = x[0];
            int v = x[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        
        
        int maxi = -1;
        
        for(int i = 0 ;i < n ; i++){
            for(int j = i +1 ; j < n ; j++){
                int u = i;
                int v = j;
                
                int rank = adjList[i].size() + adjList[j].size();
                // network rank of two different cities
                
                for(auto x : adjList[i]){
                    if(x == v){
                        // u and v are connected;
                        rank--;
                    }
                }
                
                maxi = max(maxi, rank);
            }
        }
        
        
        return maxi;
        
        
        
        
    }
};