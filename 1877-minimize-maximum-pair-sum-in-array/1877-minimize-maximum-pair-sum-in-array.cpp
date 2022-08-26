class Solution {
public:
    int minPairSum(vector<int>& nums) {
        /*
        
        3,5,4,2,4,6
        
        
        2, 3, 4, 4, 5, 6
        
        
        
        2,3,3,5
        
        */
        
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
        
        
        
    }
};