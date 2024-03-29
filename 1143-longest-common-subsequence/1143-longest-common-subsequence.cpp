class Solution {
public:
    
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i == 0 || j == 0 ){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s1[i-1] == s2[j-1]){
            return dp[i][j] =  1 + f(i-1, j-1, s1, s2, dp);
        }
        else{
            return dp[i][j] = max(f(i-1, j, s1, s2, dp), f(i, j-1, s1, s2, dp));
        }
    }
    int longestCommonSubsequence(string s1, string s2) {
        
        int n1  = s1.size();
        int n2 = s2.size();
        
        // vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        // return f(n1-1, n2-1, s1, s2, dp);
        
        //tabulation
        
        vector<vector<int>> dp(n1+2, vector<int>(n2+2, 0));
        
        for(int i =1 ; i<= n1 ; i++){
            for(int j = 1 ; j <= n2 ; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] =  1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // now trying to print LCS
        int i = n1;
        int j = n2;
        string ans = "";
        while(i>0 && j > 0){
            if(s1[i] == s2[j]){
                ans += s1[i];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        
        reverse(ans.begin(), ans.end());
        cout << "Longest Common Subsequence = " << ans << endl;
        
        
        return dp[n1][n2];
        
        
//         //tabulation with space
        
//         vector<int> curr (n2+2, 0);
//         vector<int> prev (n2+2, 0);
        
        
//         for(int i =1 ; i<= n1 ; i++){
//             for(int j = 1 ; j <= n2 ; j++){
//                 if(s1[i-1] == s2[j-1]){
//                     curr[j] =  1 + prev[j-1];
//                 }
//                 else{
//                     curr[j] = max(prev[j], curr[j-1]);
//                 }
//             }
            
//             prev = curr;
//         }
        
//         return prev[n2];
        
        
    }
};