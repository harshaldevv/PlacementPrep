class Solution {
public:
    bool isvalid(int &i, int &j, int &m, int &n){
        return i>=0 && i < m && j >=0 && j < n;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<vector<int>> q;
        int fresh =0 ;
        bool vis[m][n];
        memset(vis, 0, sizeof(vis));
        
        for(int i = 0; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 2)   {
                    
                 // rotten orange
                    vis[i][j] = true;
                    q.push({i,j});
                 }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        
        if(fresh == 0){
            return 0;
        }
        
        int t = 0;
        vector<int> dir{1,0,-1,0,1};
        while(!q.empty()){
            int sz = q.size();
            t++;
            while(sz--){
                auto front = q.front();
                q.pop();
                int currx = front[0];
                int curry = front[1];
                
                for(int k = 0 ; k <4 ; k++){
                    int newx = currx + dir[k];
                    int newy = curry + dir[k+1];
                    
                    if(isvalid(newx, newy, m,n) && !vis[newx][newy] && grid[newx][newy] == 1){
                        // grid[newx][newy] = 2;
                        vis[newx][newy] = true;
                        fresh--;
                        q.push({newx, newy});
                    }
                }
                
            }
        }
        
        // cout << "fresh = " << fresh << endl;
        if(fresh >0){
            // cout << "here" << endl;
            return -1;
        }
        else{
            return t-1;
        }
        
        
        
    }
};