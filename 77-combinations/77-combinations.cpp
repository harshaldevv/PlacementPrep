class Solution {
public:
    void solve(int i,vector<int> &nums, vector<int> &holder,vector<vector<int>> &ans, int k){
        
        if(holder.size() == k){
            ans.push_back(holder);
            return ;
        }
        
        if(i >= nums.size()){
            return ;
        }
        
        //exclude
        solve(i+1, nums, holder, ans, k);
        
        //include
        holder.push_back(nums[i]);
        solve(i+1, nums, holder, ans, k);
        
        //backtrack
        holder.pop_back();
        
        return ;
        
        
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> nums;
        
        for(int i =1 ; i <= n ; i++){
            nums.push_back(i);
        }
        
        vector<vector<int>> ans;
        
        vector<int> holder;
        
        int i = 0;
        
        solve(i, nums, holder, ans, k);
        
        
        return ans;
        
    }
};