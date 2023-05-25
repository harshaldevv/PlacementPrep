class Solution {
public:
    
    int f(int i, int j, vector<vector<int>> &dp){
        if(i == 0 && j == 0){
            return 1;
        }
        
        if(i == 0 || j == 0){
            return 1;
        }
        
        if(i < 0 || j < 0){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int up = f(i-1, j, dp);
        int left = f(i, j-1, dp);
        
        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n) {
        
//         vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
//         // return f(m-1, n-1, dp);
        
        
//         dp[0][0] = 1;
        
//         for(int i = 0 ; i < m ; i++){
//             dp[i][0] = 1;
//         }
        
//         for(int i = 0 ; i < n ; i++){
//             dp[0][i] = 1;   
//         }
        
//         for(int i = 1 ; i< m; i++){
//             for(int j = 1 ; j < n ; j++){
                
//                 int up = dp[i-1][j];
//                 int left = dp[i][j-1];

//                 dp[i][j] = up + left;
                
//             }
//         }
        
//         return dp[m-1][n-1];
        
        //space optimisation
        vector<int> prev(n, 1);  // 1D array for the previous row
        vector<int> curr(n, 1);  // 1D array for the current row
        
        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                curr[j] = curr[j-1] + prev[j];
            }
            
            prev = curr;
        }
        
        return prev[n-1];
        
        
        
        
        
        
        
        
    }
};