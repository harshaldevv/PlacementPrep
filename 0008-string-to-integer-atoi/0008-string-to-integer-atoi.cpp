class Solution {
public:
    int myAtoi(string s) {
        //hci research
        
        int i = 0, sign = 1, num = 0;
        // Skip leading whitespace
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        // Check for sign
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        // Process digits
        while (i < s.length() && isdigit(s[i])) {
            // Check for overflow
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) {
                return (sign == -1) ? INT_MIN : INT_MAX;
            }
            num = num * 10 + (s[i] - '0');
            i++;
        }
        return num * sign;
    }
};
