class Solution {
public:
    void f(int i, int sum, vector<int> &holder, vector<vector<int>> &ans, int target, vector<int> &nums){
        if(sum == target){
            ans.push_back(holder);
            return ;
        }

        if(i >= nums.size()  || sum > target){
            return ;
        }

        // pick
        // pick it once and then skip all the duplicates
        holder.push_back(nums[i]);
        f(i+1, sum + nums[i], holder, ans, target, nums);

        // backtrack
        holder.pop_back();

        while( i < nums.size() -1 && nums[i] == nums[i+1]){
            i++;
        }

        // now skipped all duplicates
        // aka do the not pick case
        f(i+1, sum, holder, ans, target, nums);

        return ;
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        // since i need to skip duplicate elements in this to avoid duplicate subsets in the answer
        // so i will sort it

        sort(nums.begin(),nums.end());

        int sum = 0;
        vector<int> holder;
        vector<vector<int>> ans;
        
        f(0, sum, holder, ans, target, nums);
        return ans;
        
    }
};