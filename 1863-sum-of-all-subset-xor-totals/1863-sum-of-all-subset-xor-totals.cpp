class Solution {
public:
    int helper(vector<int> &nums, int i, int sum){
        if(i >= nums.size()){
            return sum;
        }
        
        int include = helper(nums, i+1, sum ^nums[i]); // include the ith element
        int exclude = helper(nums, i+1, sum); // exlcuding the ith element
        
        return include+exclude ; 
        // Ab hume iska toh sum karna hoga
        // cuz we hume sum karna hai include wala case + exclude wala case
        
    }
    int subsetXORSum(vector<int>& nums) {
        int i = 0;
        int sum = 0;
        return helper(nums, i, sum);
        
    }
};