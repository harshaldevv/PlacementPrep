class Solution {
public:
    
    bool isvalid(int i, int j, int m, int n){
        return i>=0 && i < m && j>=0 && j < n;
    }
    
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        queue<vector<int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        // return the distance of the nearest 0 for each cell.
        // therefore push all zeroes pehle
        // kyuki all zeroes ki distance mil jayega 
        
        // phir hum baadme non zeroes ki dist calculate kr lenge
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0){
                    q.push({i,j,0});
                    vis[i][j] = true;
                }
            }
        }
        vector<int> dir{1,0,-1,0,1};

        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                auto front = q.front(); q.pop();
                
                int x = front[0];
                int y = front[1];
                int dist = front[2];
                // cout << "x = " << x << ", y = " << y << " dist = " << dist << endl;
                
                ans[x][y] = dist;
                
                for(int k = 0 ; k < 4 ; k++){
                    int newx = x + dir[k];
                    int newy = y + dir[k+1];
                    
                    if(isvalid(newx, newy, m , n) && !vis[newx][newy]){
                        q.push({newx, newy, dist+1});
                        vis[newx][newy] = true;
                    }
                }
            }
        }
        
        return ans;
        
    
        
    }
};