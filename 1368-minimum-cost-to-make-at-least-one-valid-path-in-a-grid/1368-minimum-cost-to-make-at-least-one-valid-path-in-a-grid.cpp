class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        
        //hci research
        int m = grid.size();
        int n = grid[0].size();
        
        // Define a vector to store the distances
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        // Define a priority queue to store the nodes
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        // Add the start node to the priority queue
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        // Define the directions to move in the grid
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int cost = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            
            // If we have reached the target node, return the cost
            if (x == m - 1 && y == n - 1) {
                return cost;
            }
            
            // Check all four directions
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // Check if the new cell is within the grid
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newCost = cost;
                    
                    // If the new cell requires a modification, add 1 to the cost
                    if (grid[x][y] != i + 1) {
                        newCost++;
                    }
                    
                    // If the new cost is less than the current distance, update the distance
                    if (newCost < dist[nx][ny]) {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }
        
        return -1;  // Return -1 if the target node is unreachable
    }
};
