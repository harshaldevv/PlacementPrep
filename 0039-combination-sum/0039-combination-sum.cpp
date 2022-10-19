class Solution {
public:
    
    void helper(int indx, int sum, vector<int> &holder, vector<vector<int>> &ans, vector<int> &nums, int &target){
        
        if(sum > target){
            return ;
        }
        
        if(sum == target){
            ans.push_back(holder);
            return;
        }
        
        if(indx >= nums.size()){
            return ;
        }
        
        //exclude
        helper(indx +1, sum, holder, ans, nums, target);
        
        // include
        sum += nums[indx];
        holder.push_back(nums[indx]);
        helper(indx, sum, holder, ans, nums, target);
        
        
        //backtrack
        sum-=nums[indx];
        holder.pop_back();
        
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candi, int target) {
        int sum = 0;
        
        int i = 0;
        
        vector<vector<int>> ans;
        vector<int> holder;
        
        helper(i, sum, holder, ans, candi, target);
        
        return ans;
        
    }
};