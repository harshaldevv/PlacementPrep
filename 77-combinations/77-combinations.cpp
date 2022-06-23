class Solution {
public:
    
   
    
    void solve(vector<int>&nums, int i, int n, int k, vector<int> &holder,  vector<vector<int>> &ans){
        
        
        if(holder.size() == k){
            ans.push_back(holder);
            return ;
        }
        
        if(i == n){
            return ;
        }
        
        //include
        holder.push_back(nums[i]);
        solve(nums, i+1, n, k, holder,ans);
        
        //exclude
        holder.pop_back();
        solve(nums, i+1, n, k, holder, ans);
        
        return ;
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans;
        vector<int> holder; // empty set
        vector<int> nums;
        
        for(int i = 1 ; i <= n ; i++){
            nums.push_back(i);
        }
        
        solve(nums, 0, n, k, holder, ans);
        return ans;
    }
};