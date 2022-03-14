class Solution {
public:
    int t[5000+1];
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        return iterativeDP(nums, nums.size());
        
        
        
        
//         int n = nums.size();
//         if(n<3){
//             return 0;
//         }
        
//         // vector<int> t(n, -1);
//         memset(t, -1,  sizeof(t));
//         return dp2(nums, n, 0);
//         // return dp(nums, n, 0);
        
    }
    
    int iterativeDP(vector<int> &nums, int n){
        if(n<3){
            return 0;
        }
        
        int sum = 0;
        int dp[n];
        dp[0] = 0;
        dp[1] = 0;
        
        for(int i = 2 ; i < n ; i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                dp[i] = dp[i-1] +1;
            }
            else{
                dp[i] = 0;
            }
            
            sum+= dp[i];
        }
        
        return sum;
    }
    

    
    
    int dp2(vector<int> &nums, int n, int res){
        
        if(n<3){
            t[n] = 0;
            return t[n];
        }
        
        if(t[n] != -1){
            return t[n];
        }
        
        if(nums[n-1] - nums[n-2] == nums[n-2] - nums[n-3]){
            res++;
            t[n] = res+dp2(nums, n-1, res);
        }
        else{
            t[n] = dp2(nums, n-1, 0);
        }
        
        return t[n];
    }
    
    
    int dp(vector<int> &nums, int n, int res){
        
        if(n<3){
            return 0;
        }
           
        if(nums[n-1] - nums[n-2] == nums[n-2] - nums[n-3]){
            res++;
            return res + dp(nums, n-1,res);
        }
        else{
            return dp(nums, n-1,0);
        }
        
    }
};