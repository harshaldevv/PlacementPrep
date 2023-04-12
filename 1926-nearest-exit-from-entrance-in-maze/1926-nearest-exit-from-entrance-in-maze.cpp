class Solution {
public:
    bool isvalid(int i, int j, int m, int n){
        return i>=0 && i < m && j >=0 && j < n;
    }
    bool isValidExit(int cx, int cy, int x, int y, vector<vector<char>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        // cout << "here = " << cx << " " << cy << endl;
        if(grid[cx][cy] != '.'){
            return false;
        }
        
        if(cx == 0 || cx == m-1 || cy == 0 || cy == n-1){
            // border found
            if(cx != x || cy != y){
                return true;
            }
        }
        
        return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        
        
        int x = entrance[0];
        int y = entrance[1];
        
        queue<vector<int>> q;
        q.push({x,y, 0});
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        vis[x][y] = true;
        
        vector<int> dir{1,0,-1,0,1};
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto front = q.front(); q.pop();
                int cx = front[0];
                int cy = front[1];
                int d = front[2];
                
                if(isValidExit(cx, cy, x,y, maze)){
                    return d; 
                }
                
                for(int k = 0 ; k < 4 ; k++){
                    int newx = cx + dir[k];
                    int newy = cy + dir[k+1];
                    
                    if(isvalid(newx, newy, m, n) && !vis[newx][newy] && maze[newx][newy] == '.'){
                        q.push({newx, newy, d+1});
                        vis[newx][newy] = true;
                    }
                }
            }
        }
        
        return -1;
        
    }
};