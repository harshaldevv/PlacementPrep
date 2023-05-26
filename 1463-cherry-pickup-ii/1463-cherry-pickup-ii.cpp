class Solution {
public:
    int f(int i, int j1, int j2, vector<vector<int>> &grid, int &m, int &n, vector < vector < vector < int >>> &dp){
        if( j1 < 0 || j2 < 0 || j1 >= n || j2 >= n || i >= m){
            return 0;
        }
        
        if(i == m-1){
            if(j1 == j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        
        if(dp[i][j1][j2] != -1){
            return dp[i][j1][j2];
        }
        
        int ans = INT_MIN;
        for(int x = -1 ; x <= 1 ; x++){
            for(int y = -1; y <= 1 ; y++){
                int val = f(i+1, j1+x, j2+y, grid, m, n, dp);
                
                if(j1 == j2){
                    val += grid[i][j1];
                }
                else{
                    val += (grid[i][j1] + grid[i][j2]);
                }
                
                ans = max(ans, val);
            }
        }
        return dp[i][j1][j2] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        
        // vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(n+1, -1))); //mine
        // return f(0,0, n-1, grid, m, n, dp);
        
        //tabulation
        // i-> 0 to m-1 -->now i = m-1 to 0
        
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(n+1, -1))); //mine
        for(int j1 = 0 ; j1 < n ; j1++){
            for(int j2 = 0 ; j2 < n ; j2++){
                if(j1 == j2){
                    dp[m-1][j1][j2] = grid[m-1][j1];
                }
                else{
                    dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
                }
            }
        }
        
        for(int i = m-2 ; i >= 0 ; i--){
            for(int j1 = 0 ; j1 < n ; j1++){
                for(int j2 = 0 ; j2 < n ; j2++){
                    
                    int ans = INT_MIN;
                    for(int x = -1 ; x <= 1 ; x++){
                        for(int y = -1; y <= 1 ; y++){
                            int val = 0;
                            
                            if(j1+x >= 0 && j1+ x < n && j2+y >= 0 && j2+y < n){
                                val = dp[i+1][j1+x][j2+y];    
                            }
                            else{
                                val = INT_MIN;
                            }
                            
                            if(j1 == j2){
                                val += grid[i][j1];
                            }
                            else{
                                val += (grid[i][j1] + grid[i][j2]);
                            }

                            ans = max(ans, val);
                        }
                    }
                    
                    dp[i][j1][j2] = ans;
                }
            }
        }
        
        return dp[0][0][n-1];
        
    }
};