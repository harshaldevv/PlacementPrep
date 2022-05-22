class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int fresh = 0;
        
        queue<pair<int, int>> q;
        
        for(int i = 0 ; i< m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                else if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        
        int dx[4] = {0,0, -1,+1};   // left, right, top, down
        int dy[4] = {-1, +1, 0, 0}; // left, right, top, down 
        
        int t = -1; // time
        
        /***
        we increment time whenever we get rotten oranges. 
        The ones which are rotten when they are encountered then also we 
        will increment, but it should be zero at that point,
        so initializing with -1 ensures that at that point in time it 
        will be zero
        ***/
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int, int> pr = q.front();
                q.pop();
                int x = pr.first;
                int y = pr.second;
                
                // wanna move around all the four directions of this rotten orange
                for(int i = 0 ; i < 4 ; i++){
                    int newX = x + dx[i];
                    int newY = y + dy[i];
                    
                    if(newX >= 0 && newX < m && newY >= 0 && newY < n){
                        // valid coordinates
                        if(grid[newX][newY] == 1){
                            grid[newX][newY] = 2;
                            q.push({newX, newY});
                            fresh--;
                        }
                    }
                }                
            }
            // cout << "at t = " << t << " , fresh oranges left = " << fresh << endl;
            t++;
            
        }
        
        if(fresh == 0){
            return t == -1 ? 0 : t ; 
            //we initialised with -1, so if there were no oranges it'd take 0 mins.
        }
        else{
            return -1;
        }
        
    }
};