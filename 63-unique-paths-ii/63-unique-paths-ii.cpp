class Solution {
public:
    int dp[100+1][100+1];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        // normal recursion -- gives TLE --> 27/41 passed
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        memset(dp, -1, sizeof(dp));
        
        return helper(0, 0, obstacleGrid);
        
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