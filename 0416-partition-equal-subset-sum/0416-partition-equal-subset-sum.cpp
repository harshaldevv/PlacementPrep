class Solution {
public:
    bool f(int i, int j, vector<int> &nums, vector<vector<int>> &dp ){
        // cout << i << " , " << j << endl;
        
        if(j == 0){
            return true;
        }
        
        if(i == 0 ){
            return nums[i] == j;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        
        bool notTake = f(i-1, j, nums, dp);

        bool take = false;
        
        if(j >= nums[i]){
            take = f(i-1, j - nums[i], nums, dp);
        }
        
        return dp[i][j] = take | notTake;
        
    }
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        int s = 0;
        for(auto &x : nums){
            s+=x;
        }
        
        if(s%2 !=0){
            return false;
        }
        
        int ss = s/2;
        vector<vector<int>> dp(n, vector<int>(ss+1, -1));
        
        return f(n-1, ss, nums, dp);
        
    }
};