class Solution {
public:
    
    void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> &holder, int start, int end, int sum, bool prev, int target){
        
        if(sum == target){
            ans.push_back(holder);
            return ;
        }
        
        if(start >= end || sum > target || nums[start] > target){
            return ;
        }
        
        //exclude
        helper(nums, ans, holder, start+1, end, sum, false, target);
        
        //if i ignore a number, then dont pick it up EVER
        int i = start;
        if(i>0 && nums[i] == nums[i-1] && !prev){
            return ;
        }
        
        //include
        holder.push_back(nums[start]);
        helper(nums, ans, holder, start+1, end, sum+nums[start], true, target);
        
        //backtrack
        holder.pop_back();
        return ;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> holder;
        
        bool prev = false;
        
        int i = 0;
        int sum = 0;
        
        helper(nums, ans, holder, i, nums.size(), sum, prev,  target);
        
        return ans;
        
    }
};