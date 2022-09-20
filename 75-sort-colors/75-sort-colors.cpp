class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int l = 0;
        int r = n-1;
        
        
        for(int i = 0 ; i <= r ; ){
            if(nums[i] == 0){
                swap(nums[l], nums[i]);
                l++;
                i++;
            }
            else if(nums[i] == 2){
                swap(nums[r], nums[i]);
                r--;
                
            }
            else{
                // nums[i] == 1
                i++;
            }
        }
        
        return ;
    }
};