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
        
        int ans = INT_MAX;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        for(int j = 0 ; j < n ; j++){
            int temp = f(m-1, j, matrix, m, n, dp);
            ans = min(ans, temp);
        }
        return ans;

        
    }
};