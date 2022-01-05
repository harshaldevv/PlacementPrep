class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        if(nums.size() <=1){
            return nums;
        }
        
        if(nums.size() == 2){
            if(nums[0]%2 != 0 && nums[1]%2 == 0){
                swap(nums[0], nums[1]);
                return nums;
            }
        }
        
        
        int i = 0 ;
        int j = nums.size() -1;
        
        while ( i <=j){
            if(nums[i]%2 != 0 &&  nums[j]%2 == 0){
                swap(nums[i], nums[j]);   
                i++;
                j--;
            }
            else if(nums[i]%2 == 0 && nums[j]%2 == 0){
                i++;
                continue;
            }
            else{
                // nums[i]%2 != 0 && nums[j]%2 != 0
                j--;
            }
            
            
        }
        
        return nums;
        
    }
};