class Solution {
public:
    void solve(int i, int sum, vector<int> &nums, vector<int> &holder, vector<vector<int>> &ans, int target, bool pre){
        
        if(sum == target){
            ans.push_back(holder);
            return ;
        }
        
        if(sum> target || i >= nums.size()){
            return ;
        }
        
        int e = nums[i];
        
        //exclude
        solve(i+1, sum, nums, holder, ans, target, false);
        if(i>0 && nums[i] == nums[i-1] && !pre){
            return ;
        }
        
        //key thing here
        // if im ignoring x, then i have to ignore all the occurences all of x that come 
        // aka i also wont take those occurencs of x
        
        // include
        holder.push_back(e);
        solve(i+1, sum+e, nums, holder, ans, target, true);
        
        holder.pop_back();
        
        // //exclude
        // holder.pop_back();
        // solve(i+1, sum, nums, holder, ans, target);
        
        return ;
        
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> holder;
        int sum = 0;
        
        solve(0, sum, nums, holder, ans, target,false);
        
        return ans;
        
    }
};