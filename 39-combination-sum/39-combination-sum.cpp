class Solution {
public:
    
    void solve(int i, vector<int> &nums, int sum, vector<int> &holder, vector<vector<int>> &ans, int target){
        
        if(sum == target){
            ans.push_back(holder);
            return ;
        }
        
        if(sum > target || i >= nums.size()){
            return ; // yahan koi fyda hai
            // terminatino condition
            // agar humari target hi greater than sum, ho gaya toh toh koi fyda hi nahi hai
            // aage recursion calls lagani ki
            
            // aur agar i = nums.size(), ho gaya, toh aage koi fyda nahi jane ki cuz array ka end aa gaya
        }
        
        int e = nums[i];
        // include
        holder.push_back(e);
        solve(i, nums, sum+e, holder, ans, target);
        
        // NOTE --> 
        // is ques me kuch bhi nahi tha
        // bas ye tha ki if you are including the element e, 
        // then unlike question (subset, subset 2, combination)
        // jahan hum include krne ke baad bhi i+1, kar dete hai
        // yahan hum log i+1, nahi karenge (in case of inclusion of element e)
        // the reason being becasue we are allowed to take a number any number of times
        // by taking "i", instead of "i+1", we are still able to consider the numbs[i].
        // had we had done i+1, then we would have lost the opportunity to include nums[i] in our
        // sum again.
        
        
        // but if we are not taking element e, then we can obviously go ahead with i+1;
        
        //exclude
        holder.pop_back();
        solve(i+1, nums, sum, holder, ans, target);
        
        return ;
        
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        // sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        vector<int> holder;
        
        int sum = 0;
        
        solve(0, nums, sum, holder, ans, target);
        
        return ans;
    }
};