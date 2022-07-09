class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        
        // if a solution exists, we can represent them as x-1, x, x+1. 
        // What does this tell us about the number?
        
        // Notice the sum of the numbers will be 3x. Can you solve for x?
        
        vector<long long> ans;
        
        if(num%3 != 0){
            // eg -> target = 4 ---> as seen in example 3
            return ans;
        }
        else{
            // if a number when divided with 3 leaves remainder = 0, toh we got 
            // our x --> we gives us our x-1, x and x+1
            long long x = num/3;
            ans.push_back(x-1);
            ans.push_back(x);
            ans.push_back(x+1);
            return ans;
        }
    }
};