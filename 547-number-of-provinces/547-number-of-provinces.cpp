class Solution {
public:

    int findPar(int u, vector<int> &parent){
        if(u == parent[u]){
            return u;
        }
        
        //finding parent of u , (optimising the code via path compression)
        parent[u] = findPar(parent[u], parent);
        
        return parent[u];
    }
    
    void UNION(int u, int v, vector<int> &parent, vector<int> &rank){

        u = findPar(u, parent);
        v = findPar(v, parent);
        
        if(u == v){
            return ;
            // as both the points belonged to the same union set
        }
        
        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[u] > rank[v]){
            parent[v] = u;
        }
        else{
            // ranks are equal of u and v
            parent[v] = u;
            rank[u]++;
        }
        
        return ;
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        // Used this for DSU part and striver DSU Video
        // https://leetcode.com/problems/number-of-provinces/discuss/1215380/Union-by-rank-and-path-compression-using-C%2B%2B-oror-easy-to-understand
        
        
        // parent array, rank array
        int n = isConnected.size();
        vector<int> parent(n);
        vector<int> rank(n, 0);
        
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        
        // int count = n;
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(isConnected[i][j] ==1){
        
                    // make their union
                    UNION(i, j, parent, rank);
                }
            }
        }
        
        
        // used this 
        // for calculating the number of provinces after the union thing is done
        // https://leetcode.com/problems/number-of-provinces/discuss/783887/C%2B%2B-union-find-solution
        
        
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(parent[i] == i){
                count++;
            }
        }
        
        return count;
        
        
        
        
        
        
    }
};