class Solution {
public:
    
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp, int &m, int &n){
        if(i == 0 && j >=0 && j < n){
            return matrix[i][j];
        }
        else if(j < 0 || j >= n || i < 0){
            return INT_MAX;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int up = f(i-1, j, matrix, dp, m, n) ;
        int left = f(i-1, j-1, matrix, dp, m, n);
        int right = f(i-1, j+1, matrix, dp, m, n);
        
        return dp[i][j] = min({up, left, right}) + matrix[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int ans = INT_MAX;
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        for(int j = 0 ; j < n ; j++){
            ans = min(ans, f(m-1, j, matrix, dp, m, n));
        }
        
        return ans;
        
    }
};