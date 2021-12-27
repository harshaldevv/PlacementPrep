class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        if(nums.size() == 1){
            return 0;
        }
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        if(k == 0){
            return nums[n-1] - nums[0]; // last element - first element;
        }
        
        
        int left = nums[0];
        int right = nums[n-1];

        int ans = right - left;
        for(int i = 0 ; i < n -1; i ++){
            int maxi = max(nums[i] + k, right -k);
            int mini = min(nums[i +1 ] -k , left + k);
            
            ans = min(ans, maxi-mini);
                
        }
        
        return ans;
        
        
        
        
        
    }
};