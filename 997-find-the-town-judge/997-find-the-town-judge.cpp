class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        
        vector<vector<int>> adjList(n+1);
        
        for(int i = 0 ; i < trust.size() ; i++){
            int u = trust[i][0];
            int v = trust[i][1];
            
            adjList[u].push_back(v);
        }
        
        // adjList made
        
        vector<int> in(n+1, 0); // indegree wala vector
        vector<int> out(n+1, 0);
        
        for(int i = 1 ; i<= n ; i++){
            for(auto nextVertex : adjList[i]){
                in[nextVertex]++;
            }
            out[i] = adjList[i].size();
        }
        
        // check if any vertex has indegree equal to n-1 
        // if yes, return that vertex (index)
        for(int i = 1 ; i <= n ; i++){
            if(in[i] == n-1){
                // return i;
                if(out[i] == 0){
                    return i;
                }
            }
        }            
        // else return -1
        return -1;
        
    }
};