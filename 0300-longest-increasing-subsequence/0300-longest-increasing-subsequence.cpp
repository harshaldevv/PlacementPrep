class Solution {
    
        
public:
    int lengthOfLIS(vector<int>& nums) {
        //hci researhc
        int n = nums.size();
        vector<int> dp(n, 0);
        int len = 0;
        for (int num : nums) {
            int pos = lower_bound(dp.begin(), dp.begin() + len, num) - dp.begin();
            dp[pos] = num;
            if (pos == len) {
                len++;
            }
        }
        return len;
        
    }
};