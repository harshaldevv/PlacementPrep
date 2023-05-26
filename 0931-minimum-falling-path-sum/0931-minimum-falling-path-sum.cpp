class Solution {
public:
    int f(int i, int j, vector<vector<int>> &grid, int &m, int &n, vector<vector<int>> &dp){
        if(i == 0 && j >= 0 && j < n ){
            return grid[i][j];
        }
        
        //more bases cases
        if(i < 0 || i >= m || j < 0 || j >= n){
            return 1e7;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int up = f(i-1, j, grid, m, n, dp);
        int left = f(i-1, j-1, grid, m, n, dp);
        int right = f(i-1, j+1, grid, m, n, dp);
        
        return dp[i][j] = min({up, left, right}) + grid[i][j];
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
//         int ans = INT_MAX;
//         vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
//         for(int j = 0 ; j < n ; j++){
//             int temp = f(m-1, j, matrix, m, n, dp);
//             ans = min(ans, temp);
//         }
//         return ans;
        
        
        // tabulation
        // int i = 0 to m-1
        // int j = n-1 to 0
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        for(int j = 0 ; j < n ; j++){
            dp[0][j] = matrix[0][j];
        }
        
        for(int i = 1 ; i < m ; i++){
            for(int j = n-1 ; j >= 0; j--){
                
                int up = 1e7;
                int left = 1e7;
                int right = 1e7;
                
                if(i>= 1){
                    up = dp[i-1][j];
                }
                if(i>=1 && j >= 1){
                    left = dp[i-1][j-1];
                }
                
                if(i-1>= 0 && j+1 <= n-1){
                    right = dp[i-1][j+1];
                }
                
                dp[i][j] = min({up, left, right}) + matrix[i][j];
                
            }
        }
        
        int ans = INT_MAX;
        for(int j = 0 ; j < n ; j++){
            int temp = dp[m-1][j];
            ans = min(ans, temp);
        }
        return ans;
        
        
        // tabulation with 

        
    }
};