class Solution {
public:
    int characterReplacement(string s, int k) {
        // hci research
        
          int n = s.length();
        int maxCount = 0, maxLength = 0;
        vector<int> count(26, 0);
        int left = 0, right = 0;
        while (right < n) {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);
            while (right - left + 1 - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
        
    }
};