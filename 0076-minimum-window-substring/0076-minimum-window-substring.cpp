class Solution {
public:
    string minWindow(string s, string t) {
        
        // hci research
        unordered_map<char, int> tCount; // count of each character in t
        for (char c : t) {
            tCount[c]++;
        }
        int left = 0, right = 0, count = t.length();
        int minLeft = 0, minLength = INT_MAX;
        while (right < s.length()) {
            if (tCount[s[right]] > 0) {
                count--;
            }
            tCount[s[right]]--;
            right++;
            while (count == 0) {
                if (right - left < minLength) {
                    minLeft = left;
                    minLength = right - left;
                }
                tCount[s[left]]++;
                if (tCount[s[left]] > 0) {
                    count++;
                }
                left++;
            }
        }
        return (minLength == INT_MAX) ? "" : s.substr(minLeft, minLength);
    }
};
