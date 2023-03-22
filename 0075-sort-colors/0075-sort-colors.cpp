class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int k = n-1;
        
        while(j <= k){
            if(nums[j] == 2){
                swap(nums[j], nums[k]);
                k--;
            }
            else if(nums[j] == 0){
                swap(nums[j], nums[i]);
                j++;
                i++;
            }
            else{
                // nums[j] == 1;
                j++;
                
            }
        }
        
    }
};