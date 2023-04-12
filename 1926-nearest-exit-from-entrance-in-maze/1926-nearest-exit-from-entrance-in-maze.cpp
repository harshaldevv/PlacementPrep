class Solution {
public:
    bool isvalid(int &i, int &j, int &m, int &n){
        return i>=0 && i< m && j >= 0 && j < n;
    }
    bool isborder(int &i, int &j,int &m, int &n){
        return (i == 0 || i == m-1 ||j == 0 || j == n-1);
    }
    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) {
        // "+" -> wall
        // "." -> empty
        int m = grid.size();
        int n = grid[0].size();
        
        //bfs
        int ox = entrance[0];
        int oy = entrance[1];
        
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<int> dir{1,0,-1,0,1};
        
        
        queue<vector<int>> q;
        q.push({ox,oy});
        vis[ox][oy] = true;
        
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
                    
                    if(isvalid(newx,newy,m,n) && !vis[newx][newy] && grid[newx][newy] == '.'){
                        
                        if(isborder(newx, newy, m,n)){
                            return steps;
                        }
                        
                        vis[newx][newy] = true;
                        q.push({newx, newy});
                    }
                }
            }
        }
        
        return -1;

    }
};