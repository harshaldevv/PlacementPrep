class Solution {
public:
    
    void helper(vector<int> &nums, int &target, vector<vector<int>> &ans, vector<int> &holder, int i, int &n, int &sum){
        if(sum > target || i >= n){
            return ;
        }
        
        if(sum == target){
            ans.push_back(holder);
            return ;
        }
        
        //exclude
        helper(nums, target, ans, holder, i+1, n, sum);
        
        //include
        sum += nums[i];
        holder.push_back(nums[i]);
        helper(nums, target, ans, holder, i, n, sum);
        
        //backtrack
        sum-=nums[i];
        holder.pop_back();
        
        return ;
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        
        vector<int> holder;
        int i = 0;
        int n = nums.size();
        
        
        int sum = 0;
        
        helper(nums, target, ans, holder, i, n , sum);
        
        return ans;
        
    }
};