class Solution {
public:
    void solve(vector<int> &nums, int i, vector<int> &holder, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(holder);
            return;
        }
        
        int e = nums[i];
        
        //include
        holder.push_back(e);
        solve(nums, i+1, holder, ans);
        
        
        //exclude
        holder.pop_back();
        solve(nums, i+1, holder, ans);
        
        
        return ;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
//         vector<vector<int>> ans;
        
//         vector<int> holder;
        
//         solve(nums,0, holder, ans);
        
//         return ans;
        
        // RECURSIVE (BACKTRACK) METHOD ^^
        
        
        // ITERATIVE METHOD --> OP
        
        // EXPLAINATION BELOW
        /*
        [] ----------> []
        [1] ---------> [] ,  [1]
        [1,2] -------> [] ,  [1] , [2] , [1,2]
        [1,2,3] -----> [] ,  [1] , [2] , [1,2], [3], [1,3], [2,3], [1,2,3]
        */
        // basically upar walo ko sabko lelo without nums[i] (exclude case), then usko include karlo (nums[i])
        
        vector<vector<int>> ans;
        ans.push_back({});
        
        for(int i = 0 ; i < nums.size(); i++){
            int sz = ans.size();
            
            for(int j = 0 ; j < sz ; j++){
                vector<int> copy = ans[j];
                copy.push_back(nums[i]);
                ans.push_back(copy);
            }
        }
        
        return ans;
    }
};