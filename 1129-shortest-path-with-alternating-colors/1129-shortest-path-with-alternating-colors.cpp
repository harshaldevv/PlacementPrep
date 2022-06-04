class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges){
        
        bool vis[101][2];
        memset(vis, 0, sizeof(vis));
        
        vector<int> redGraph[101];
        for(int i = 0 ; i < redEdges.size() ; i++){
            int start = redEdges[i][0];
            int end = redEdges[i][1];
            redGraph[start].push_back(end);
        }
        
        vector<int> blueGraph[101];
        for(int i = 0 ; i < blueEdges.size() ; i++){
            int start = blueEdges[i][0];
            int end = blueEdges[i][1];
            blueGraph[start].push_back(end);
        }
        
        queue<pair<int, int>> q; // node, color(0 for red, 1 for blue)
        q.push({0,0}); 
        q.push({0,1});
        vis[0][0] = 1;
        vis[0][1] = 1;
        
        int count = 0;
        vector<int> ans(n, INT_MAX);
        
        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                auto front = q.front();
                q.pop();
                int node = front.first;
                int col = front.second;
                ans[node] = min(count, ans[node]);
                

                if(col == 0){
                    for(auto x : blueGraph[node]){
                        if(!vis[x][1]){
                            vis[x][1] = 1;
                            q.push({x,1});
                        }
                    }
                }
                else{
                    // col = 1;
                    for(auto x : redGraph[node]){
                        if(!vis[x][0]){
                            vis[x][0] = 1;
                            q.push({x,0});
                        }
                    }
                }
            }
            count++;
        }
        
        
        for(int i = 0 ; i< n ; i++){
            if(ans[i] == INT_MAX){
                ans[i] = -1;
            }
        }
        
        return ans;
        
    }
};