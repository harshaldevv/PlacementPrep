class Solution {
public:
    void helper(vector<int> &nums, vector<int> &holder, vector<vector<int>> &ans, int k, int i, int n){
        if(holder.size() == k){
            ans.push_back(holder);
            return ;
        }
        
        if(i >= n){
            return ;
        }
        //exclude
        helper(nums, holder, ans, k, i+1, n);
        
        //include
        holder.push_back(nums[i]);
        helper(nums, holder, ans, k , i+1, n);
        
        //backtrack
        holder.pop_back();
        
        return ;
        
    }
    
    void helper2(int k, int n, int curr, vector<int> &holder, vector<vector<int>> &ans){
        if(holder.size() == k){
            ans.push_back(holder);
        }
        
        
        for(int i = curr ; i <= n ; i++){
            holder.push_back(i);
            helper2(k, n, i+1, holder, ans);
            holder.pop_back();
        }
        
        return ;
    }
    vector<vector<int>> combine(int n, int k) {
        
//         vector<int> temp;
//         for(int i = 1 ; i <= n ; i++){
//             temp.push_back(i);
//         }
        
//         vector<vector<int>> ans;
//         vector<int> holder;
//         int i = 0;
//         helper(temp, holder, ans, k, i, n);
        
//         return ans;
        
        vector<vector<int>> ans;
        vector<int> holder;
        helper2(k, n, 1, holder, ans);
        
        return ans;
        
    }
};