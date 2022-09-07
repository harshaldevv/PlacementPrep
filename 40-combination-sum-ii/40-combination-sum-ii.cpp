class Solution {
public:
    void solve(int i, int sum, vector<int> &holder, vector<vector<int>> &ans, vector<int> &nums,int k, bool prev){
        
        if(sum == k){
            ans.push_back(holder);
            return ;
        }
        
        if(i >= nums.size() || sum > k){
            return ;
        }
        
        
        
        //exclude
        solve(i+1, sum, holder, ans, nums, k, false);
        
        //if we ignore x , then we need to ignore all further instances of x
        if(i >0 && nums[i] == nums[i-1] && !prev){
            return ;
        }
        
        // include
        holder.push_back(nums[i]);
        solve(i+1, sum + nums[i] , holder, ans, nums, k, true);
        
        //backtrack
        holder.pop_back();
        
        return ;
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        
        vector<vector<int>> ans;
        
        vector<int> holder;
        
        int i = 0;
        int sum = 0;
        
        solve(i, sum, holder, ans, nums, k, false);
        
        return ans;
    }
};