class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        
        int l = 0;
        int r = n-1;
        
        int ans = min(nums[l], nums[r]) * (r-l);
        
       
        while(l<r){
            
            int h = min(nums[l], nums[r]);
            ans = max(ans, (r-l)*h);
            
            while(nums[l] <= h && l < r){
                l++;
            }
            while(nums[r] <= h && l < r){
                r--;
            }
            
            
       
        }
        
        return ans;
        
        
        
    }
};