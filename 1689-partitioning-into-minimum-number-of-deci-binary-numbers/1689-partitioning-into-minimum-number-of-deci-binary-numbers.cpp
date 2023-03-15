class Solution {
public:
    int minPartitions(string n) {
        
    //hci research
    int max_digit = 0;
    for(char c : n) {
        int digit = c - '0';
        max_digit = max(max_digit, digit);
    }
    return max_digit;
        
    }
};