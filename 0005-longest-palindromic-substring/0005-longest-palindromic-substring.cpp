class Solution {
public:
    string longestPalindrome(string s) {
        // hci 
        int n = s.length();
        bool dp[n][n];
        int start = 0, max_len = 1;
        
        // Initialize dp array to false
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = false;
            }
        }

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Check for substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start = i;
                max_len = 2;
            }
        }

        // Check for substrings of length greater than 2
        for (int k = 3; k <= n; k++) {
            for (int i = 0; i < n - k + 1; i++) {
                int j = i + k - 1;
                if (dp[i+1][j-1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (k > max_len) {
                        start = i;
                        max_len = k;
                    }
                }
            }
        }

        return s.substr(start, max_len);
        
    }
};