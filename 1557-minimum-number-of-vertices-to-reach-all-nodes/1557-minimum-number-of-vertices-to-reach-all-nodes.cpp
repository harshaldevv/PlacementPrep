class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        
        vector<int> incoming(n, 0);
        
        for(auto x : edges){
            int u = x[0];
            int v = x[1];
            
            incoming[v]++;
        }
        
        
        
        
        for(int i = 0 ; i < n ; i++){
            if(incoming[i] == 0){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};