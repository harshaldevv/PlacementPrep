class Solution {
public:
    void solve(vector<int> &nums, int i, vector<int> &holder, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(holder);
            return;
        }
        
        int e = nums[i];
        
        //include
        holder.push_back(e);
        solve(nums, i+1, holder, ans);
        
        
        //exclude
        holder.pop_back();
        solve(nums, i+1, holder, ans);
        
        
        return ;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        vector<int> holder;
        
        solve(nums,0, holder, ans);
        
        return ans;
        
    }
};