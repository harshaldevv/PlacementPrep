class Solution {
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i< 0 || j < 0 ){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + f(i-1, j-1, s1, s2, dp);
        }
        else{
            int a = f(i-1, j, s1, s2, dp);
            int b = f(i,j -1, s1, s2, dp);
            
            return dp[i][j] = max(a, b);
        }
        
    }
    int longestCommonSubsequence(string s1, string s2) {
        
        int n1 = s1.size();
        int n2 = s2.size();
        
        // vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        // return f(n1-1, n2-1, s1, s2, dp);
        
        //tabulation
        
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        
        // base case -> if either of the string's length is 0, toh ans = 0
        // ie dp[0][j] = 0 and dp[i][0] = 0 
        // we've already handled this by initialising dp with 0
        
        for(int i = 1 ; i <= n1 ; i++){
            for(int j = 1 ; j <= n2 ; j++){
                
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    int a = dp[i-1][j];
                    int b = dp[i][j -1];

                    dp[i][j] = max(a, b);
                }   
            }
        }
        
        return dp[n1][n2];
        
        
        
        
    }
};