class Solution {
public:
    int minimumSum(int num) {
        //hci research
        string str_num = to_string(num);
    sort(str_num.begin(), str_num.end());

    int min_sum = INT_MAX;

    do {
        int new1 = stoi(str_num.substr(0, 2));
        int new2 = stoi(str_num.substr(2));

        min_sum = min(min_sum, new1 + new2);
    } while (next_permutation(str_num.begin(), str_num.end()));
        
        return min_sum;
        
    }
};