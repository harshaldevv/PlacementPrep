class Solution {
public:
    void helper(int numb, vector<int> &holder, vector<vector<int>> &ans, int n, int k){
        if(k == 0){
            ans.push_back(holder);
            return ;
        }
        
        if(numb > n){
            return ;
        }
        
        //exclude
        if(numb <= n){
            helper(numb +1, holder, ans, n, k);
        }
        
        
        //include
        holder.push_back(numb);
        helper(numb +1, holder, ans, n, k-1);
        
        holder.pop_back();
        
        
        return;
        
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans;
        vector<int> holder;
        helper(1, holder, ans, n, k);
        return ans;
        
        
    }
};