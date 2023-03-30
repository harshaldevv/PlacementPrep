class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        //hci research -> honestly this code is much better than my code xD
        
        int n = nums.size();
        int sum = n*(n+1)/2;
        for(int i = 0; i < n; i++) {
            sum -= nums[i];
        }
        return sum;
    }
};
