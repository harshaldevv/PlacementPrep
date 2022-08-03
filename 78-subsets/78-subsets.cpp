class Solution {
public:
    
    void helper(vector<int> &nums, int i, vector<int> &holder, vector<vector<int>> &ans){
        
        if(i>= nums.size()){
            ans.push_back(holder);
            return ;
        }
        
        // exclude
        helper(nums, i+1, holder, ans);
        
        //include
        holder.push_back(nums[i]);
        helper(nums, i+1, holder, ans);
        
        //backtrack
        holder.pop_back();
        
        return ;
            
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> holder;
        helper(nums, 0, holder, ans );
        
        return ans;
        
    }
};