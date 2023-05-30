class Solution {
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i==0){
            return j;
        }
        
        if(j==0){
            return i;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = f(i-1, j-1, s1, s2, dp);
        }
        else{
            int insert = f(i, j-1, s1, s2, dp);
            int delet = f(i-1, j, s1, s2, dp);
            int replace = f(i-1, j-1, s1, s2, dp);
            
            return dp[i][j] = min({insert, delet, replace}) +1;
        }
        
    }
    int minDistance(string word1, string word2) {
        
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return f(n1, n2, word1, word2, dp);
        
    }
};