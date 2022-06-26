class Solution {
public:
    
    void solve(int i, vector<int> &nums, int sum, vector<int> &holder, vector<vector<int>> &ans, int target){
        
        if(sum == target){
            ans.push_back(holder);
            return ;
        }
        
        if(sum > target || i >= nums.size()){
            return ; // yahan koi fyda hai
        }
        
        int e = nums[i];
        // include
        holder.push_back(e);
        solve(i, nums, sum+e, holder, ans, target);
        
        
        //exclude
        holder.pop_back();
        solve(i+1, nums, sum, holder, ans, target);
        
        return ;
        
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        vector<int> holder;
        
        int sum = 0;
        
        solve(0, nums, sum, holder, ans, target);
        
        return ans;
    }
};