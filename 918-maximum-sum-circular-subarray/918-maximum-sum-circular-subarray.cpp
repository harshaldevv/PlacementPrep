class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        //case 1
        
        int case1 = kadane(nums, n);
        
        int totalSum = 0;
        for(int i = 0 ; i < n ; i++){
            totalSum += nums[i];
        }
        
        int minSubarray = negativeKadane(nums, n);
        
        if(totalSum == minSubarray){
            return case1;
        }
        else{
            cout << case1 << " " << totalSum - minSubarray << endl;
            return max(case1, totalSum - minSubarray);
        }
    }
    int negativeKadane(vector<int> &nums, int n){
        int sum = 0;
        int mini = INT_MAX;
        
        for(int i = 0 ; i < n ; i++){
            int x = (nums[i]);
            
            sum += x;
            
            mini = min(mini, sum);
            
            sum = min(sum, 0);
        }
        
        return mini;
    }
    
    int kadane(vector<int> &nums, int n){
        // normal kadane code
        int sum = 0;
        int maxi = INT_MIN;
        
        for(int i = 0 ; i < n; i++){
            int x = nums[i];
            sum+=x;
            maxi = max(maxi, sum);
            if(sum <0){
                sum = 0;
            }
        }
        
        return maxi;
    }
};