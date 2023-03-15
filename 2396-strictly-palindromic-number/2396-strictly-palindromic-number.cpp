class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        
        for (int b = 2; b <= n - 2; b++) {
            int num = n;
            string str;
            while (num > 0) {
                str += to_string(num % b);
                num /= b;
            }
            int len = str.length();
            for (int i = 0; i < len / 2; i++) {
                if (str[i] != str[len - 1 - i]) {
                    return false;
                }
            }
        }
        return true;
        
    }
};