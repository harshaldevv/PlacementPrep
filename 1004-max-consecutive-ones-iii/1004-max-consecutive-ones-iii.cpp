class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        
        int l = 0;
        int r = 0;
        int zerocount = 0;
        
        int ans = 0;
        
        for( ; r < n ; r++){
            if(nums[r] == 0){
                zerocount++;
            }
            
            if(zerocount > k){
                while(zerocount > k){
                    if(nums[l] == 0){
                        zerocount--;
                    }
                    l++;
                }
            }
            
            ans = max(ans, r-l+1);
        }
        
        
        
        return ans;
        
    }
};