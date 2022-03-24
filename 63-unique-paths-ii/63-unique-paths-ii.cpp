class Solution {
public:
    int dp[100+1][100+1];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        //doing tabulation
        int t[rows][cols];
        memset(t, 0 , sizeof(t));
        
        // filling first row
        for(int i = 0 ; i < cols ; i++){
            if(obstacleGrid[0][i] == 1){
                t[0][i] = 0;
                break;
            }
            else{
                t[0][i] = 1;
            }
        }
        
        //filling first column
        for(int i = 0 ; i < rows ; i++){
            if(obstacleGrid[i][0] == 1){
                t[i][0] = 0;
                break;
            }
            else{
                t[i][0] = 1;
            }
        }
        
        
        for(int i = 1 ;  i< rows ; i++){
            for(int j = 1 ; j< cols ; j++){
                if(obstacleGrid[i][j] == 1){
                    t[i][j]=0;
                }
                else{
                    t[i][j] = t[i-1][j] + t[i][j-1];
                }
            }
        }
        
        return t[rows-1][cols-1];
        
        
        
        
        
        
//         //memoziation passes all test cases --> TC - O(m+n), SC - O(m*n)
//         // normal recursion -- gives TLE --> 27/41 passed
//         int rows = obstacleGrid.size();
//         int cols = obstacleGrid[0].size();
//         memset(dp, -1, sizeof(dp));
        
//         return helper(0, 0, obstacleGrid);
        
    }
    
    int helper(int i, int j , vector<vector<int>> &matrix){
        if(i>= matrix.size() || j >= matrix[0].size()){
            return 0;
        }
        
        if(matrix[i][j] == 1){
            dp[i][j] = 0;
            return 0;
        }
        
        if( i==matrix.size() -1 && j == matrix[0].size() -1  && (matrix[i][j] == 0) ){
            dp[i][j] = 1;
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        dp[i][j]  = helper(i+1, j, matrix) + helper(i, j+1, matrix);
        return dp[i][j];
    }
};