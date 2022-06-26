class Solution {
public:
    
    void solve(vector<int> &nums, int i, int sum, vector<int> &holder, vector<vector<int>> &ans, int k, int n){
        if(holder.size() == k ){
            if(sum == n){
                ans.push_back(holder);
            }
            return;
        }
        
        if(i == nums.size()){
            return ;
        }
        
        int e = nums[i];
        
        //include
        holder.push_back(e);
        solve(nums, i+1, sum+e, holder, ans, k, n);
        
        // exclude
        holder.pop_back();
        solve(nums, i+1, sum, holder, ans, k,n);
        
        return ;
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> numb;
        for(int i = 1  ; i <= 9 ; i++){
            numb.push_back(i);
        }
        
        
        vector<vector<int>> ans;
        vector<int> holder;
        int sum = 0;
        
        solve(numb, 0, sum, holder, ans, k,n);
        
        return ans;
        
    }
};