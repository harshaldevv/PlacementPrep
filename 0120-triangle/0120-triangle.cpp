class Solution {
public:
    int helper(int i, int j, int rowMax, int colMax, vector<vector<int>> &triangle, vector<vector<int>> &dp ){
        
        if( i < 0 || i > rowMax || j < 0 || j > colMax){
            return INT_MAX;
        }
        
        if(i == rowMax){
            return dp[i][j] = triangle[i][j];
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int down1 = helper(i+1, j, rowMax, colMax, triangle, dp);
        int down2 = helper(i+1, j+1, rowMax, colMax, triangle, dp);
        // int down3 = helper(i+1, j-1, rowMax, colMax, triangle);
        
        return dp[i][j] =  triangle[i][j] + min(down1, down2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        int n = triangle[triangle.size() -1].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return helper(0,0, m-1, n-1, triangle, dp);
        
    }
};