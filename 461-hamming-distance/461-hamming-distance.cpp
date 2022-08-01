class Solution {
public:
    int hammingDistance(int x, int y) {
        
        // same as https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
        
        // therefore using the learning from the above ques
        // basically count the number of setbits in x^y 
        
        return __builtin_popcount(x^y);
        
    }
};