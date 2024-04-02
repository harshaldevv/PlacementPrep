class Solution {
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(j < 0){
            return 1;
        }
        
        if(i < 0){
            return 0;
        }
        
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        
        if(s1[i] == s2[j]){
            return dp[i][j] = f(i-1, j-1, s1, s2, dp) + f(i-1, j, s1, s2, dp);
        }
        else{
            return dp[i][j] =  f(i-1, j, s1, s2, dp);
        }
    }
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return f(n1-1, n2-1, s, t, dp);
    }
};