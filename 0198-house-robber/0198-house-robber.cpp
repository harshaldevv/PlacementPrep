class Solution {
public:
    int f(int i, vector<int> &nums, vector<int> &dp){
        if(i == 0){
            return nums[0];
        }
        else if(i == 1){
            return max(nums[0], nums[1]);
        }
        else if(i<0){
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        int left = f(i-1, nums, dp); //not pick
        int right = f(i-2, nums, dp) + nums[i]; //pick + cant take adjacent (n-1), isliye we take n-2
        
        return dp[i] =  max(left, right);
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // //memoization
        // vector<int> dp(n+1, -1);
        // return f(n-1, nums, dp);
        
        
//         // do tabulation
//         //steps 
//         // 1) initialise a dp array of size n+1
//         // 2) write the bases cases from the memoization
//         // 3) run a for loop 
//         // 4) replace f(i), f(i-1).. etc with dp[i], dp[i-1],...
//         // 5) return dp[n-1] (instead of dp[n] because we are dealing with indexes, 
//         //    therefore for "n", we get answer at index n-1
//         vector<int> dp(n+1, -1);
        
//         if(n==1){
//             return nums[0];
//         }
        
//         dp[0] = nums[0];
//         dp[1] = max(nums[0], nums[1]);
        
//         for(int i = 2 ; i <  n ; i++){
//             int left = dp[i-1];
//             int right = dp[i-2] + nums[i];
            
//             dp[i] = max(left, right);
//         }
        
//         return dp[n-1];

        // space optimisation
        
        
        
        if(n==1){
            return nums[0];
        }
        
        
        
        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);
        int curr = -1;
        
        for(int i = 2 ; i <  n ; i++){
            int left = prev;
            int right = prev2 + nums[i];
            
            curr = max(left, right);
            
            prev2 = prev;
            prev = curr;
            
        }
        
        return prev;

        
        
    }
};