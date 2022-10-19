class Solution {
public:
    void helper(int i, vector<int> &holder, vector<vector<int>> &ans, vector<int> &nums, bool prev){
        if(i >= nums.size()){
            ans.push_back(holder);
            return ;
        }
        
        //exclude
        helper(i+1, holder, ans, nums, false);
        
        if( i > 0 && nums[i] == nums[i-1] && !prev){
            return;
        }
        
        //include
        holder.push_back(nums[i]);
        helper(i+1, holder, ans, nums, true);
        
        
        //backtrack
        holder.pop_back();
        
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> holder;
        
        int i = 0;
        
        helper(i, holder ,ans, nums, false);
        
        return ans;
    }
};