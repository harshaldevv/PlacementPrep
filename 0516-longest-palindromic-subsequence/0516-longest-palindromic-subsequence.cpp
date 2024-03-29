class Solution {
public:
    int LCS(string &s1, string &s2){
//         // tabulation
//         int n1 = s1.size();
//         int n2 = s2.size();
//         vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
//         for(int i = 1 ; i <= n1 ; i++){
//             for(int j = 1; j <= n2 ; j++){
//                 if(s1[i-1] == s2[j-1]){
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//                 }
//             }
//         }
        
//         return dp[n1][n2];
        
        
        
        
        // tabulation space optimised
        int n1 = s1.size();
        int n2 = s2.size();
        vector<int> curr (n2+1, 0);
        vector<int> prev (n2+1, 0);
        
        for(int i = 1 ; i <= n1 ; i++){
            for(int j = 1; j <= n2 ; j++){
                if(s1[i-1] == s2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        
        return prev[n2];
    }
    int longestPalindromeSubseq(string s) {
        
        string s1 = s;
        string s2 = s;
        
        reverse(s2.begin(), s2.end());
        
        return LCS(s1, s2);
        
    }
};