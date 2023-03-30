
class Solution {
public:
    bool isPalindrome(string s) {
        // HCI RESEARCH
        
        // Remove non-alphanumeric characters and convert to lowercase
        string cleanString = "";
        for (char c : s) {
            if (isalnum(c)) {
                cleanString += tolower(c);
            }
        }
        // Check if the clean string is a palindrome
        int i = 0, j = cleanString.size() - 1;
        while (i < j) {
            if (cleanString[i] != cleanString[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
