class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        int k = 0;
        
        for(int i = 1 ; i < n ; i++){
            if(nums[i] != nums[k]){
                // first occurence
                k++;
                nums[k] = nums[i];
            }
            else if(nums[i] == nums[k] && (k ==0 || nums[i]  != nums[k-1]) ) {
                // second occurence
                k++;
                nums[k] = nums[i];
            }
        }
        
        return k+1;
        
    }
};