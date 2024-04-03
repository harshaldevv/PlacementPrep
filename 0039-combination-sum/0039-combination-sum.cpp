class Solution {
public:
    void f(int i, int j, int sum, int target, vector<int> &candidates, vector<int> &holder, vector<vector<int>> &ans){
        if(sum == target){
            ans.push_back(holder);
            return;
        }
        
        if(i >= j || sum >target){
            return ;
        }
        
        // include
        sum += candidates[i];
        holder.push_back(candidates[i]);
        f(i, j, sum,target, candidates, holder, ans);
        
        
        //backtrack
        sum -= candidates[i];
        holder.pop_back();
        
        // exclude
        f(i+1, j, sum, target, candidates, holder, ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> holder;
        
        int sum = 0;
        int n = candidates.size();
        f(0, n, sum, target, candidates, holder, ans);
        
        
        return ans;
    }
};