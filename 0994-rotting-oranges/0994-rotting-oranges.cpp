class Solution {
public:
    bool isvalid(int &i, int &j, int &m, int &n){
        return i>=0 && i < m && j >=0 && j < n;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int t = -1;
        queue<vector<int>> q; // we will always push rotten oranges ONLY (even during BFS)
        int rottenCount = 0;
        int freshCount = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 2){
                    // rotten
                    rottenCount++;
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }
        
        vector<int> dir{1,0,-1,0,1};
        
        while(!q.empty()){
            auto sz = q.size();
            bool rotten = false ; // captures if we rot some oranges or not
            while(sz--){
                auto front = q.front();
                q.pop();
                int currx = front[0];
                int curry = front[1];
                
                for(int k = 0 ; k < 4 ; k++){
                    int newx = currx + dir[k];
                    int newy = curry + dir[k+1];
                    
                    if(isvalid(newx, newy, m,n)){
                        if(grid[newx][newy] == 1){
                            grid[newx][newy] = 2;
                            freshCount--;
                            rotten = true;
                            q.push({newx, newy});
                        }                        
                    }   
                }
            }
            
            t++;
        }
        
        if(freshCount == 0){
            if(t==-1){
                return 0;
            }
            else{
                return t;
            }
        }
        else{
            return -1;
        }
        
    }
};