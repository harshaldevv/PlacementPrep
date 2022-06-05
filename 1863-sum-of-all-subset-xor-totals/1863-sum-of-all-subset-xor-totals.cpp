class Solution {
public:
    int helper(vector<int> &nums, int i, int sum){
        if(i == nums.size()){
            return sum;
        }
        int include = helper(nums, i+1, sum ^nums[i]);
        int exclude = helper(nums, i+1, sum);
        return include + exclude;
    }
    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0);
    }
};