class Solution {
public:
    
    void solve( int i, vector<int> &nums, vector<vector<int>> &ans){
        if( i ==  nums.size()){
            ans.push_back(nums);
            return ;
        }
        
        for(int j = i ; j < nums.size() ; j++){
            swap(nums[i], nums[j]);
            solve(i+1, nums, ans);
            swap(nums[i], nums[j]); // backtrack step
                
        }
        
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        int i = 0;
        solve( i, nums, ans);
        
        return ans;
        
    }
};