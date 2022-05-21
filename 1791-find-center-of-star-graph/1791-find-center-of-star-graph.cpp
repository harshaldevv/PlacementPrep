class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int vertices = edges.size() +1;
        
        vector<int> inDegree(vertices+1, 0);
        
        for(auto &t : edges){
            inDegree[t[0]]++;
            inDegree[t[1]]++;
        }
        
        int Totaledges = vertices -1;
        
        for(int i = 1 ; i <= vertices ; i++){
            if(inDegree[i] == Totaledges){
                return  i;
            }
        }
        return -1;
    
    }
};