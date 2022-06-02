class Solution {
public:
    // vector<int> parent;
    // vector<int> rank;
    
    int findPar(int u, vector<int> &parent){
        if(u == parent[u]){
            return u;
        }
        
        //finding parent of u , (optimising the code via path compression)
        parent[u] = findPar(parent[u], parent);
        
        return parent[u];
    }
    
    void UNION(int u, int v, vector<int> &parent, vector<int> &rank){
        // cout << "hello" << endl;
        u = findPar(u, parent);
        v = findPar(v, parent);
        // cout << "hello 22" << endl;
        
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
                    // cout << "here" << endl;
                    UNION(i, j, parent, rank);
                    // cout << "here too" << endl;
                }
            }
        }
        
        //use unordered set to count the number of leader of unions 
        //leaders of union eventually represent the number of unnions
        
        int count = 0;
        
        for(int i = 0 ; i < n ; i++){
            if(parent[i] == i){
                count++;
            }
        }
        
        return count;
        
        // return 5;
        
        
        
    }
};