class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 0 ;
        int r = 1;
        
        while(r < n){
            if(nums[r] != nums[l]){
                nums[l+1] = nums[r];
                l++;
            }
            r++;
        }
        
        return l+1;
        
    }
};