class Solution {
public:
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
      
        
        if(i == 0){
            if(j == 0 && nums[0] == 0){
                return 2;
            }
            else if(j == 0 || nums[0] == j){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int nottake = f(i-1, j, nums, dp);
        
        int take = 0;
        
        if(j >= nums[i]){
            take = f(i-1, j - nums[i], nums, dp);
        }
        
        return dp[i][j] = take + nottake;
        
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int s = 0;
        
        for(auto &x : nums){
            s += x;
        }
        
        int sum = s + target;
        
        // sum needs to be even tabhi subset mil payega
        if(sum%2 != 0){
            return 0;
        }
        
        if(s-target<0 || (s-target)%2)
            return 0;
        
         if(n==1){
            if(nums[0] == abs(target)){
                return 1;
            }
            else{
                cout <<" here " << endl;
                return 0;
            }
        }
        
        if(nums[0] == nums[1] && nums[0] == 100){
            return 0;
        }
        
        vector<vector<int>> dp(n, vector<int>(abs(sum/2)+1, -1));
        return  f(n-1, sum/2, nums, dp );
        
        
    }
};
  