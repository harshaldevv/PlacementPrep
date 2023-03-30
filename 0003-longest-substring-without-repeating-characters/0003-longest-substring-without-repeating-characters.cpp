class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // hci research
        unordered_set<char> window;
    int start = 0, maxLength = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (window.count(c)) {
            while (s[start] != c) {
                window.erase(s[start++]);
            }
            window.erase(s[start++]);
        }
        window.insert(c);
        maxLength = max(maxLength, i - start + 1);
    }
    return maxLength;
        
    }
};