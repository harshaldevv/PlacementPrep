class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // make adjList
        vector<vector<int>> adjList[n];
        for(auto &x : flights){
            int u = x[0];
            int v = x[1];
            int price = x[2];
            adjList[u].push_back({v, price});
        }
        
        // pq
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({0,src, 0}); // hops, currnode, distfrom src
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            
            int currhops = front[0];
            int currcity = front[1];
            int currdist = front[2];
            
            if(currhops > k){
                continue;
            }
            
            for(auto &next : adjList[currcity]){
                int nextcity = next[0];
                int edgeWt = next[1];
                
                if(currdist + edgeWt  < dist[nextcity]){
                    dist[nextcity] = currdist + edgeWt;
                    pq.push({currhops +1, nextcity, dist[nextcity]});
                }
            }
        }
        
        if(dist[dst] == INT_MAX){
            return -1;
        }
        else{
            return dist[dst];
        }
        
        
    }
};