class Solution {
public:
    bool isvalid(int i, int j, int m ,int n){
        return i>=0 && i < m && j >= 0 && j < n;
    }
    int maxDistance(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        queue<vector<int>> q;
        int land = 0;
        int water = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    // land
                    land++;
                    q.push({i,j});
                }
                else{
                    water++;
                }
            }
        }
        
        if(land == 0 || water == 0){
            return -1;
        }
        
        int ans = -1;
        vector<int> dir{-1,0,1,0,-1};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        while(!q.empty()){
            int sz = q.size();
            ans++;
            while(sz--){
                auto front = q.front(); q.pop();
                
                int x = front[0];
                int y = front[1];
                
                
                for(int k = 0 ; k < 4 ; k++){
                    int newx = x + dir[k];
                    int newy = y + dir[k+1];
                    
                    if(isvalid(newx, newy, m, n) && !vis[newx][newy] && grid[newx][newy] == 0){
                        q.push({newx, newy});
                        vis[newx][newy] = true;
                    }
                }
            }
        }
        
        return ans;
        
    }
};