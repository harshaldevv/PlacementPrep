class Solution {
public:
    bool isValid(int i, int j, int n){
        if(i< 0 || j < 0 || i >= n || j >= n){
            // invalid coordinates
            return false;
        }
        return true;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        
        int x = 0;
        int y = 0;
        if(grid[x][y] == 1){
            return -1;
        } 
        
        int tx = n-1;
        int ty = n-1;
        
        if(x== tx && y == ty){
            return 1;
        }
        
        int dir[8][2] = { {-1,0}, {1,0}, {0, -1}, {0, 1}, {-1, +1}, {+1, +1}, {+1, -1}, {-1,-1}   };
        
        queue<pair<int, int>> q;
    
        q.push({x,y});
        vis[x][y] = true;
        
        int steps = 0;
        
        while(!q.empty()){
            int sz = q.size();
            // cout << "size = " << sz << endl;
            steps++;
            while(sz--){
                
                auto front = q.front();
                q.pop();
                int currx = front.first;
                int curry = front.second;
                
                if(currx == tx && curry == ty){
                    return steps;
                }
                
                for(int k = 0 ; k < 8 ; k++){
                    int newx = currx + dir[k][0];
                    int newy = curry + dir[k][1];
                    
                    if(isValid(newx, newy, n) && !vis[newx][newy] && grid[newx][newy] == 0){
                        q.push({newx, newy});
                        vis[newx][newy] = true;
                    }
                }
            }
        }
        
        return -1;
        
    }
};