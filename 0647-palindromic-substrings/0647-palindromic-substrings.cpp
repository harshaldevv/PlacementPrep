class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        
        // Create a 2D array of size n x n to store whether a substring from i to j is palindrome or not
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        
        // For all substrings of length 1, mark them as palindrome
        for(int i=0; i<n; i++) {
            dp[i][i] = true;
            count++;
        }
        
        // For all substrings of length 2, mark them as palindrome if both characters are same
        for(int i=0; i<n-1; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
                count++;
            }
        }
        
        // For all substrings of length 3 or more, mark them as palindrome if both end characters are same and middle substring is also palindrome
        for(int k=3; k<=n; k++) {
            for(int i=0; i<n-k+1; i++) {
                int j = i+k-1;
                if(dp[i+1][j-1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    count++;
                }
            }
        }
        
        return count;
    }
};
