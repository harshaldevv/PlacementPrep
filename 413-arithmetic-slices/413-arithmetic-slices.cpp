class Solution {
public:
    
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3){
            return 0;
        }
        
        return dp(nums, n, 0);
        
    }
    
    int dp(vector<int> &nums, int n, int res){
        
        if(n<3){
            return 0;
        }
           
        if(nums[n-1] - nums[n-2] == nums[n-2] - nums[n-3]){
            res++;
            return res + dp(nums, n-1,res);
        }
        else{
            return dp(nums, n-1,0);
        }
        
    }
};