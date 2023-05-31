class Solution {
public:
    int f(int i, int prevIndex, vector<int> &nums, vector<vector<int>> &dp){
        if( i>= nums.size()){
            return 0;
        }
        if(dp[i][prevIndex+1] != -1){
            return dp[i][prevIndex+1];
        }
        
        int nottake = f(i+1, prevIndex, nums, dp);
        
        int take = 0;
        
        if(prevIndex == -1 || nums[i] > nums[prevIndex]){
            take = 1 + f(i+1, i, nums, dp);
        }
        //bas store karne ke lie prevIndex me +1 kia, kyuki prevIndex goes from -1 to n-1 
        // therefore prevIndex +1 -> goes from 0 to n.
        return dp[i][prevIndex+1] = max(take, nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // f(i, prevIndx) -> means length of LIS starting from i indx 
        // and having prevIndx as previous Index
        
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return f(0, -1, nums, dp);
        
        
        // tabulation
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i = n-1 ; i >=0 ; i--){
            for(int j = n-1 ; j>= -1 ; j--){
                
                int nottake = dp[i+1][j+1];
        
                int take = 0;

                if(j == -1 || nums[i] > nums[j]){
                    take = 1 + dp[i+1][i+1];
                }
                
                dp[i][j+1] = max(take, nottake);   
            }
        }
        
        return dp[0][0];
        
        
    }
};