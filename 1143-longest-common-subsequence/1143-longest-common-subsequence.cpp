class Solution {
public:
    
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i < 0 || j < 0){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int op1 = 0;
        if(s1[i] == s2[j]){
            op1 =  1 + f(i-1, j-1, s1, s2, dp);
            return dp[i][j] = op1;
        }
        else{
            int op2 = f(i, j-1, s1, s2, dp);
            int op3 = f(i-1, j, s1, s2, dp);
            return dp[i][j] =  max(op2, op3);
        }
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int n1 = text1.size();
        int n2 = text2.size();
        
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return f(n1-1, n2-1, text1, text2, dp);
        
    }
};