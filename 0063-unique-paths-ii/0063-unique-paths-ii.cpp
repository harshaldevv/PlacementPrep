class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp){
        if(i ==0 && j == 0){
            if(grid[i][j] == 1){
                //stone
                return 0;
            }
            else{
                return 1;
            }
        }
        
         if(i < 0 || j < 0 ){
            return 0;
        }
        
        if(grid[i][j] == 1){
                //stone
            return 0;
        }
        
       
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int up = f(i-1, j, grid, dp);
        int left = f(i, j-1, grid, dp);
        
        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
//         // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
//         // return f(m-1, n-1, grid, dp);
        
        
//         //base case
        
//         if(grid[0][0] == 1){
//             return 0;
//         }
//         // tabulation
//         for(int i = 0 ; i < m ; i++){
//             for(int j = 0 ; j < n ; j++){
                
//                 if(grid[i][j] == 1){
//                     //stone
//                     dp[i][j] =  0;
//                 }
//                 else if(i == 0 && j == 0){
//                     dp[i][j] =1 ;
//                 }
//                 else{
//                     int up = 0;
//                     int left = 0;
                    
//                     if(i >=1 ){
//                         up = dp[i-1][j];
//                     }
                    
//                     if(j >=1 ){
//                         left = dp[i][j-1];
//                     }
                    
//                     dp[i][j] = up + left;
//                 }
//             }
//         }
        
        
//         return dp[m-1][n-1];
        
        
        // tabulation with space optimisation
        
        vector<int> curr(n, 0);
        vector<int> prev(n, 0);
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                
                if(grid[i][j] == 1){
                    //stone
                    curr[j] =  0;
                }
                else if(i == 0 && j == 0){
                    curr[j] = 1 ;
                }
                else{
                    int up = 0;
                    int left = 0;
                    
                    if(i >=1 ){
                        up = prev[j];
                    }
                    
                    if(j >=1 ){
                        left = curr[j-1];
                    }
                    
                    curr[j] = up + left;
                }
            }
            
            prev = curr;
        }
        
        return prev[n-1];
        
        
        
    }
};