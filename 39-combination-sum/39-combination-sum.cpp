class Solution {
public:
    
    void solve(int i, int sum, vector<int> &holder, vector<vector<int>> &ans, vector<int> &nums, int k){
        
        if(i >= nums.size() || sum > k ){
            return ;
        }
        
        if(sum == k ){
            ans.push_back(holder);
            return ;
        }
        
        //include
        holder.push_back(nums[i]);
        solve(i, sum + nums[i], holder, ans, nums, k);
        
        // backtrack
        holder.pop_back();
        
        // exclude
        solve(i+1, sum, holder, ans, nums, k);
        
        return ;
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int k) {
        
        vector<vector<int>> ans;
        
        vector<int> holder;
        
        int i = 0;
        int s = 0;
        
        solve(i, s, holder, ans , nums, k);
        
        return ans;
        
    }
};