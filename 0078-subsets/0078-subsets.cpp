class Solution {
public:
    
    void helper(vector<int> &nums , int start, int &end, vector<int> &holder, vector<vector<int>> &ans){
        if(start >= end){
            //put in ans
            ans.push_back(holder);
            return ;
        }
        
        //exclude
        helper(nums, start+1, end, holder, ans);
        
        //include
        holder.push_back(nums[start]);
        helper(nums, start+1, end, holder, ans);
        
        //backtrack
        holder.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int i = 0;
        
        vector<int> holder;
        int n = nums.size();
        
        helper(nums, i, n, holder, ans);
        
        
        return ans;
        
    }
};