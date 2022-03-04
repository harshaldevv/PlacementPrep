class Solution {
public:
    int jump(vector<int>& nums) {
        //return solve(nums, 0);
        
        vector<int> t(nums.size() , -1);
        return solve2(nums, 0, t);
    }
    
    int solve(vector<int> &nums, int currPos){
        if(currPos >= nums.size() -1){
            return 0;
        }
        if(currPos + nums[currPos] >= nums.size() -1){
            return 1;
        }
        
        int mn = INT_MAX;
        for(int i = currPos ; i< currPos + nums[currPos]; i++){
            cout << " i = " << i << endl;
            mn = min(mn, solve(nums, i));
            
        }
        
        return mn+1;
        
        
    }
    
    int solve2(vector<int> &nums, int currPos, vector<int> &dp){
        if(currPos >= nums.size()){
            return 0;
        }
        if(currPos == nums.size() -1){
            return dp[currPos] = 0;
        }
        
        if(currPos + nums[currPos] >= nums.size() -1){
            return dp[currPos] = 1;
        }
        
        if(dp[currPos] != -1){
            return dp[currPos];
        }
        
        
        int mn = INT_MAX-10;
        for(int i = currPos+1; i <= currPos + nums[currPos] ; i++){
            mn = min(mn, solve2(nums, i, dp));
        }
        
        dp[currPos] = mn+1;
        return dp[currPos];
    }
};