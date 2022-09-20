class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int zero = 0;
        
        int l = 0;
        int r = 0;
        int ans = 0;
        int n = nums.size();
        
        for( ; r < n ; r++){
            if( nums[r] == 0){
                zero++;
                
                while(zero > k){
                    if(nums[l] == 0){
                        zero--;
                    }
                    l++;
                }
            }
            
            ans = max(ans, r - l +1);
            
        }
        
        
        return ans;
        
    }
};