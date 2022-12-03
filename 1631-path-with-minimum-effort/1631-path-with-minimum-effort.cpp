class Solution {
public:
    bool isvalid(int &i, int &j, int &m, int &n){
        return i>=0 && i < m && j >=0 && j < n;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        // dijkstra
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        dist[0][0] = 0;
        
        vector<int> dir{1,0,-1,0,1};
        
        pq.push({0,{0,0}}); // dist, x, y
        // cout << "pq size " << pq.size() << endl;
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            
            int d = front.first;
            int x = front.second.first;
            int y = front.second.second;
            
            if(x == m-1 && y == n-1){
                return d;
            }
            // cout << "entered" << endl;
            for(int k = 0 ; k < 4 ; k++){
                int newx = x + dir[k];
                int newy = y + dir[k+1];
                
                if(isvalid(newx, newy, m, n)){
                    // cout << "here22" << endl;
                    int temp = abs(heights[newx][newy] - heights[x][y]);
                    int newEffort = max(temp, d);
                    // cout << "newEffort = " << newEffort << endl;
                    if(newEffort < dist[newx][newy] ){
                        dist[newx][newy] = newEffort;
                        // cout << "here" << endl;
                        pq.push({newEffort, {newx, newy}});
                    }
                }
            }
            
        }
        
        return -5;
    }
};