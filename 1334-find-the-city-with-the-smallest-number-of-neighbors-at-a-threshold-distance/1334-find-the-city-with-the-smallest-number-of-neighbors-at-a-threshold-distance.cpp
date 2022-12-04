class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // can be done more easily via floyd warshall algo as it is multi source shortest path algo
        // but since mereko abhi dijsktra (single source shortest algo) aata hai toh uski ke through karrha
        vector<vector<int>> adjList[n];
        
        for(auto &x : edges){
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
        
        
        int globalcounter = INT_MAX; 
        // holds the count of "smallest number of cities that are reachable through some path"
        
        int globalAnswer = -1; 
        // holds the "city" with the smallest number of cities that are reachable through 
        // some path and whose distance is at most distanceThreshold
        
        for(int i = 0 ; i < n ; i++){
            vector<int> dist(n, INT_MAX);
            
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
            
            dist[i] = 0; // "i" = source
            
            pq.push({0, i}); // dist, node
            
            while(!pq.empty()){
                auto front = pq.top();
                pq.pop();
                
                int currdist = front[0];
                int currnode = front[1];
                
                for(auto &next : adjList[currnode]){
                    int nextcity = next[0];
                    int edgeWt = next[1];
                    
                    if(dist[currnode] + edgeWt < dist[nextcity] ){
                        dist[nextcity] = dist[currnode]  + edgeWt;
                        pq.push({dist[nextcity], nextcity});
                    }
                }
            }
            
            // dijkstra done
            
            
            int tempCounter = 0; // counts how many distances are within the distance threshold
            
            for(auto &d : dist){
                if(d <= distanceThreshold){
                    tempCounter++;
                }
            }
            
            if(tempCounter > 0 ){
                // cout << "temp, globalcounter = " << temp << " , " << globalcounter << endl;
                if(tempCounter <= globalcounter){
                    globalcounter = tempCounter;
                    globalAnswer = i;
                }
            }
        }
        
        return globalAnswer;
    }
};