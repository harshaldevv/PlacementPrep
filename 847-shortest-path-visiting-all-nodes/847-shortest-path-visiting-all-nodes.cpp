class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n==1){return 0 ;}
        
        int finalstate = (1<<n) -1;
        
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(1<<n)) ; 
        // [how many nodes][each node may have 2^n visited bit]
        
        for(int i = 0 ; i < n ; i++){
            q.push({i, (1<<i)});
        }
        
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            steps++;
            
            while(sz--){
                
                auto fr = q.front();
                int node = fr.first;
                int state = fr.second;
                q.pop();
                
                if(state == finalstate){
                    return steps-1;
                }
                
                for(auto x : graph[node]){
                    // cout << "x = " << x << endl;
                    int newstate = state | (1<< x);
                    
                    if(vis[x][newstate]){continue;}
                    
                    vis[x][newstate] = 1;
                    
                    q.push({x, newstate});
                }
            }
        }
        
        return -1;
    }
};