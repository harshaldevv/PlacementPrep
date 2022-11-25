class Solution {
public:
    vector<int> dir{1,0,-1,0,1};
    bool isvalid(int i, int j, int m, int n){
        return i>=0 && i < m && j >=0 && j<n;
    }
    
    void dfs(vector<vector<int>> &grid, int i, int j, int &m, int &n, queue<vector<int>> &q, vector<vector<bool>> &vis){
        if(!isvalid(i,j,m,n)){
            return ;
        }
        if(grid[i][j] != 1){
            return ; // water (0)
        }
        if(vis[i][j]){
            return ;
        }
        
        vis[i][j] = true;
        q.push({i,j});
        
        for(int k = 0 ; k < 4 ; k++){
            int newx = i + dir[k];
            int newy = j + dir[k+1];
            dfs(grid, newx, newy, m, n, q, vis);
        }
        
        return ;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        bool found = false;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ;j++){
                if(grid[i][j] == 1){
                    dfs(grid, i,j, m, n, q, vis);
                    found = true;
                    break;
                }
            }
            if(found){
                break;
            }
        }
        
        cout << q.size() << endl;
        // dfs done
        
        int steps = 0;
        
        while(!q.empty()){
            int sz = q.size();
            steps++;
            
            while(sz--){
                auto front = q.front();
                q.pop();
                
                int currx = front[0];
                int curry = front[1];
                
                for(int k = 0 ; k < 4 ; k++){
                    int newx = currx + dir[k];
                    int newy = curry + dir[k+1];
                    
                    if(isvalid(newx, newy, m, n) && !vis[newx][newy] ){
                        cout << "newx, newy = " << newx << ", " << newy << endl;
                        if(grid[newx][newy] == 1){
                            return steps-1;
                        }
                        
                        vis[newx][newy] = true;
                        q.push({newx, newy});
                    }
                }
            }
        }
        
        return -10;
        
    }
};