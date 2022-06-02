class Solution {
public:
    
    bool static comp (const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b){
        return a.second < b.second;
    }
    
    int findPar(int i, vector<int> &parent){
        if(i == parent[i]){return i;}
        parent[i] = findPar(parent[i], parent);
        return parent[i];
    }
    void UNION(int u, int v, vector<int> &parent, vector<int> &rank ){
        u = findPar(u, parent);
        v = findPar(v, parent);
        
        if(u==v){
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
        int n = points.size();
        vector<pair<pair<int, int>,int>> graph;
        for(int i = 0 ; i < n ; i++){
            for(int j = i +1 ;  j < n ; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph.push_back({{i,j}, dist});
            }
        }
        
        // sort graph
        sort(graph.begin(), graph.end(), comp);
        
        int cost = 0;
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }
        
        for(int i = 0 ; i < graph.size() ; i++){
            int a = graph[i].first.first;
            int b = graph[i].first.second;
            int wt = graph[i].second;
            
            // cout << a << " , " << b << " , " << wt << endl;
            
            if(findPar(a, parent) != findPar(b, parent)){
                cost+= wt;
                UNION(a,b, parent, rank);
            }
        }
        
        return cost;
        
    }
};