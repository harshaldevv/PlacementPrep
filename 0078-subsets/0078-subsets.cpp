class Solution {
public:
    
    void helper(vector<int> &holder, int indx, vector<vector<int>> &ans, vector<int> &nums){
        
        if(indx >= nums.size()){
            ans.push_back(holder);
            return ;
        }
        
        // at every number i have 2 choice , to include or to exclude
        
        //exclude
        helper(holder, indx +1, ans, nums);
        
        //include
        holder.push_back(nums[indx]);
        helper(holder, indx +1, ans, nums); //recurse
        
        
        holder.pop_back(); // back track
        
        return;
        
        
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int i = 0;
        vector<int> holder;
        
        helper(holder, i, ans, nums);
        
        return ans;
        
    }
};