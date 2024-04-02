class Solution {
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i <= 0 || j <= 0){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s1[i-1] == s2[j-1]){
            return dp[i][j] =  1 + f(i-1, j-1, s1, s2, dp);
        }
        else{
            return dp[i][j] = max(f(i-1,j,s1, s2, dp), f(i, j-1, s1, s2, dp));
        }
        
        
    }
    string shortestCommonSupersequence(string s1, string s2) {
        
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        int LCS =  f(n1, n2, s1,s2, dp);
        
        cout << "LCS = " << LCS << endl;
        
        int scs_length = n1+n2 - LCS;
        cout << "SCS length = " <<scs_length << endl;
        
        string ans = "";
        
        int i = n1;
        int j = n2;
        
        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                ans += s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans += s1[i-1];
                i--;
            }
            else{
                ans += s2[j-1];
                j--;
            }
        }
        
         while(i > 0){
             ans += s1[i-1];
             i--;
         }
        
        while(j > 0){
             ans += s2[j-1];
             j--;
         }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
        
    }
};