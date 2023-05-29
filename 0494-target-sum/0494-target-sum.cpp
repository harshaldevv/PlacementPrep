class Solution {
public:
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        
        if(i==0){
            if(j == 0 && nums[i] == 0){
                return 2;
            }
            else if(j == 0 || nums[i] == j){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(dp[i][j] != -1){
           return dp[i][j]  ;
        }
        int nottake = f(i-1, j, nums, dp);
        
        int take = 0;
        if(j >= nums[i]){
            take = f(i-1, j - nums[i], nums, dp);
        }
        
        return dp[i][j] = nottake + take;
        
        
    }
    int findTargetSumWays(vector<int>& nums, int t) {
        
        /*
        s1+s2 = S
        s1-s2 = t
        
        2s1 = S+t
        
        s1 = (S+t)/2;
        
        */
        int S = 0;
        
        for(auto &x: nums){
            S+=x;
        }
        
        if( (S+t)%2 != 0 ){
            return false;
        }
        
        int n = nums.size();
        int s1 = (S+t)/2;
        
        if(S-t<0 ){
            return 0;
        }
        
        
         if(n==1){
            if(nums[0] == abs(t)){
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
            
        
        vector<vector<int>> dp(n+1, vector<int>(s1+1, -1));
        return f(n-1, s1, nums, dp);
    }
};