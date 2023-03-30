class Solution {
public:
    int getSum(int a, int b) {
        //hci research 
        int carry;
        while (b != 0) {
            carry = a & b;
            a ^= b;
            b = (unsigned int) carry << 1;
        }
        return a;
    }
};
