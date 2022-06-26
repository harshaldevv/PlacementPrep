class Solution {
public:
    void solve(int i, vector<int> nums, vector<vector<int>> &ans){
        //nums is passed by value
        if(i== nums.size()){
            ans.push_back(nums);
            return ;
        }
        
        for(int j = i ; j < nums.size() ; j++){
            
            if(j != i && nums[i] == nums[j] ){
                continue;
            }
            
            swap(nums[i], nums[j]);
            solve(i+1, nums, ans);
            
            //exclude
            //swap(nums[i], nums[j]);
        }
        
        return ;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        solve(0, nums, ans);
        
        return ans;
    }
};