class Solution {
public:
    bool isvalid(int &i, int &j, int &m, int &n){
        return i>=0 && i < m && j >=0 && j< n;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> ans(m, vector<int> (n,-1));
        queue<vector<int>> q;
        
        // push all 1s
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        vector<int> dir{1,0,-1,0,1};
        
        int steps = 0;
        
        while(!q.empty()){
            auto sz = q.size();
            
            while(sz--){
                auto front = q.front();
                q.pop();
                
                int currx = front[0];
                int curry = front[1];
                
                for(int k = 0 ; k < 4 ; k++){
                    int newx = currx + dir[k];
                    int newy = curry + dir[k+1];
                    
                    if(isvalid(newx, newy, m, n) && ans[newx][newy] == -1){
                        ans[newx][newy] = ans[currx][curry] +1;
                        q.push({newx, newy});
                    }
                }
            }
        }
        
        return ans;
    }
};