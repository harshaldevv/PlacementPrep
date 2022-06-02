class Solution {
    struct Node{
        int u, v, wt;
        Node(int first, int second, int weight){
            u = first;
            v = second;
            wt = weight;
        }
    };
    
public:
    
    bool static comp( Node a, Node b){
        return (a.wt < b.wt);
    }
    
    int findPar(int u, vector<int> &parent){
        if( u == parent[u]){
            return parent[u];
        }
        parent[u] = findPar(parent[u], parent);
        return parent[u];
    }
    
    void UNION(int u, int v, vector<int> &parent, vector<int> &rank){
        u = findPar(u, parent);
        v = findPar(v, parent);
        
        if(u == v){
            return ;
        }
        
        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[u] > rank[v]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
        
        return ;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size() ; // number of points
        
        // make graph (wt, u, v)
        vector<Node> edges;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1; j < n ; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                Node noi = Node(i,j,dist);
                edges.push_back(noi);
                // cout << noi.u << " , " << noi.v << " , " << noi.wt << endl;
            }
        }
        
        // sort the graph
        sort(edges.begin(), edges.end(), comp);
        
        
        //
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }
        
        int cost = 0;
        for(int i = 0 ; i < edges.size() ; i++){
            int a = edges[i].u;
            int b = edges[i].v;
            
            
            int weight = edges[i].wt;
        
            a = findPar(a, parent);
        
            b = findPar(b, parent);
            
            if(a != b){
                cost += weight;
                
                UNION(a, b, parent, rank);
            }
        }
        
        
        return cost;
    }
};