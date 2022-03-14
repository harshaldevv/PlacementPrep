class Solution {
    
    int dp[200+1][200+1];
    
    int helper(int currRow, int currCol, vector<vector<int>> &triangle){
        if(currRow <= -1){
            return 0;
        }
        
        if(currCol == -1 || currCol == triangle[currRow].size()){
            return 10000000;
        }
        
        if(dp[currRow][currCol] != -1){
            return dp[currRow][currCol];
        }
        
        int ans = INT_MAX;
        
        ans = min(ans, triangle[currRow][currCol] +  helper(currRow -1, currCol -1, triangle));
        ans = min(ans, triangle[currRow][currCol] +  helper(currRow -1, currCol   , triangle));
        
        dp[currRow][currCol] = ans;
        return dp[currRow][currCol];
    }
    
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int maxCols = triangle[rows-1].size();
        
        int ans = INT_MAX;

        memset(dp, -1, sizeof(dp));
        
        // traversing from the last row 
        for(int i = 0 ; i < maxCols ; i++){
            ans = min(ans, helper(rows-1, i, triangle));
        }
        
        return ans;
        
        
    }
};