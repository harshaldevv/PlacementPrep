class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //hci research -->
        int n = s.length();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);
        dp[0] = true; // empty string is always in the dictionary
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
        
    }
};