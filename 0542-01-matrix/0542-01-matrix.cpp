class Solution {
public:
    bool isvalid(int i, int j, int m, int n){
        return i>= 0 && i < m && j >=0 && j < n;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        queue<vector<int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        for(int i = 0 ; i < m ;i++){
            for(int j = 0 ; j < n ; j++){
                
                if(grid[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = true;
                }
            }
        }
        vector<int> dir{1,0,-1,0,1};
        int dist = 0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto front = q.front();
                q.pop();
                
                int currx = front[0];
                int curry = front[1];
                
                
                for(int k = 0 ; k <4 ; k++){
                    int newx = currx + dir[k];
                    int newy = curry + dir[k+1];
                    
                    if(isvalid(newx,newy,m,n) &&  !vis[newx][newy]){
                        ans[newx][newy] = ans[currx][curry] +1;
                        vis[newx][newy] = true;
                        q.push({newx, newy});
                    }
                    
                }   
            }
        }
        
        return ans;
        
    }
};