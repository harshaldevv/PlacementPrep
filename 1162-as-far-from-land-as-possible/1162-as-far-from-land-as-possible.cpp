class Solution {
public:
    bool isvalid(int &i, int &j, int &m, int &n){
        return i>=0 && i < m && j >= 0 && j < n;
    }
    int maxDistance(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int land = 0; // land = 1 
        int water = 0; // water = 0
        queue<vector<int>> q;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    land++;
                    q.push({i,j,0});
                }
                else{
                    water++;
                }
            }
        }
        
        if(land == 0 || water == 0){
            return -1;
        }
        
        int maxdist = 0;
        
        vector<int> dir{1,0,-1,0,1};
        
        while(!q.empty()){
            auto sz = q.size();
            maxdist++;
            while(sz--){
                auto front = q.front();
                q.pop();
                int currx = front[0];
                int curry = front[1];
                
                for(int k = 0 ; k < 4 ; k++){
                    int newx = currx + dir[k];
                    int newy = curry + dir[k+1];
                    
                    if(isvalid(newx, newy, m,n) && grid[newx][newy] == 0){
                        q.push({newx, newy});
                        grid[newx][newy] = 2;
                    }
                }
            }
        }
        
        return maxdist-1;
        
    }
};