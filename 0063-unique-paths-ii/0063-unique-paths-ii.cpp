class Solution {
public:
    
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i == 0 & j == 0 && grid[i][j] == 0){
            // obstacle toh nahi haina ye check kia grid[i][j] == 0 se
            return 1;
        }
        else if(i < 0 || j < 0){
            return 0;
        }
        else if(grid[i][j] == 1){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        
        return dp[i][j] = f(i-1, j, grid, dp) + f(i, j-1, grid, dp);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // return f(m-1, n-1, grid, dp);
        
        //tabulation
        
        if(grid[0][0] == 1){
            // obstacle hai starting point pe hi so cant move ahead
            return 0;
        }
        
        // dp[0][0] = 1;
        
        //filling the row
        for(int i = 0 ; i < n ; i++){
            cout << "i = " << i << " ; ";
            if(grid[0][i] == 1){
                cout << "hrer";
                dp[0][i] = 0;
                cout << "hrersdsds";
                break;
            }
            else{
                dp[0][i] = 1;
            }
        }
        
        //filling the col
        for(int i = 0 ; i < m ; i++){
            // cout << "j = " << i << " ; ";
            if(grid[i][0] == 1){
                dp[i][0] = 0;
                break;
            }
            else{
                dp[i][0] = 1;
            }
        }
        
        
        
        
        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                if(grid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
    
        return dp[m-1][n-1];
    }
};
  