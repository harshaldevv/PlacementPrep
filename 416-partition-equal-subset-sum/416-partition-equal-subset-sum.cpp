class Solution {
public:
    
    bool subsetSum(vector<int> &nums, int sum){
        int n = nums.size();
        int W = sum;
        
        
        int t[n+1][W+1];
        
        //filling first row
        for(int j = 0 ; j < W +1 ; j++){
            t[0][j] = false;
        }
        
        for(int i = 0 ; i < n+1 ; i++){
            t[i][0] = true;
        }
        
        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 1 ; j < W+1 ; j++){
                if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }
                else{
                    t[i][j] =  t[i-1][j];
                }
            }
        }
        
        return t[n][W];
        
    }
    bool canPartition(vector<int>& nums) {
        // knapsack variation
        
        int sum = 0;
        
        for(auto x : nums){
            sum+=x;
        }
        
        if(sum%2 != 0){
            return false;
        }
        
        return subsetSum(nums, sum/2);
        
    }
};