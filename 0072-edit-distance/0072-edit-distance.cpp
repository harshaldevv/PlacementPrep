class Solution {
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        
        
        if(i < 0){
            return j+1;
        }
        
        if(j < 0){
            return i+1;
        }
        
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s1[i] == s2[j]){
            // character has matched
            // do nothing
            return dp[i][j] = f(i-1, j-1, s1,s2, dp);
        }
        else{
            int insertStep = 1 + f(i, j-1, s1, s2, dp);
            int deleteStep = 1 + f(i-1, j, s1, s2, dp);
            int replaceStep = 1 + f(i-1,j-1, s1, s2, dp);
            
            
            return dp[i][j] =  min(insertStep, min(deleteStep, replaceStep));
            
        }
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        // vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        // return  f(n1-1, n2-1,  word1, word2, dp);
        
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        
        for(int i = 0 ; i <= n1 ; i++){
            for(int j = 0 ; j <= n2 ; j++){
                if(i == 0){
                    dp[i][j] = j;
                }
                else if(j == 0){
                    dp[i][j] = i;
                }
            }
        }
        
        for(int i = 1 ; i <= n1 ; i++){
            for(int j = 1 ; j <= n2 ; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int insertStep = 1 + dp[i][j-1];
                    int deleteStep = 1 + dp[i-1][j];
                    int replaceStep = 1 + dp[i-1][j-1];
                    dp[i][j] =  min(insertStep, min(deleteStep, replaceStep));
                }
            }
        }
        
        
        return dp[n1][n2];
    }
};