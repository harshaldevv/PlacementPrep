class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, int m, int n, vector<vector<int>> &dp){
        if(i == m-1 ){
            return triangle[i][j];
        }
        else if(j > n){
            //redudant base case
            // we will never go out of boundary even if we move diagnoally
            // kyuki 0,0 -> 1,1-> 2,2----> hamesha triangle ke andar rahenge.
            return INT_MAX;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int down =  triangle[i][j] + f(i+1, j, triangle, m, n, dp);
        int diagonal =  triangle[i][j] +  f(i+1, j+1, triangle, m, n, dp);
        
        return dp[i][j] = min(down, diagonal) ;
        
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        //this question is a "Fixed Starting Point and Variable Ending Point"
        // theefore instead of from last row (variable), bcz we have multiple starting points 
        // from the last row
        // but we have only one starting point from the top row.. hence we choose the first row
        
        // therefore f(0,0) = minimum path sum from 0,0 to the last row
        
        //f(0,0) = min( f(1, 0) , f(1, 1) )
        
        
        
        int m = triangle.size();
        int n = triangle[m-1].size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return f(0, 0, triangle, m, n, dp);
        
        
    }
};