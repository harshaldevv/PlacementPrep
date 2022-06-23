class Solution {
public:
    void solve(vector<int> &nums, int i, vector<int> &holder, vector<vector<int>> &ans, set<vector<int>> &S){
        if(i== nums.size()){
            if(S.find(holder) == S.end()){
                S.insert(holder);
                ans.push_back(holder);
            }
            
            return;
        }
        
        //include
        holder.push_back(nums[i]);
        solve(nums, i+1, holder, ans, S);
        
        //exlcude
        holder.pop_back();
        solve(nums, i+1, holder, ans, S);
        
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        vector<int> holder;
        set<vector<int>> S;
        solve(nums, 0, holder, ans, S);
        
        return ans;
        
    }
};