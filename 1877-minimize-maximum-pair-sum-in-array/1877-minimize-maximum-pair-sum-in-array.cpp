class Solution {
public:
    int minPairSum(vector<int>& nums) {
       
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int l = 0;
        int r = n-1;
        
        int ans = INT_MIN;
        while(l<r){
            ans = max(ans, nums[l] + nums[r]);
            l++;
            r--;
        }
        
        return ans;
        
        /*
        https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/discuss/1499532/Short-and-Easy-Explanation-or-2-Approaches-or-C%2B%2B-or-Beginner-friendly
        
        check O(n) TC in this link
        
        */
        
        
        
        
    }
};