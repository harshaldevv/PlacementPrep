class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        // written below is the 3 pass solution which can be brought down into 2 pass and even to one pass
        // I wrote it in 3 pass for sake of code clarity
        
        //case 1
        
        int case1 = kadane(nums, n);  // case1 == maxSubbaraySum 
        
        int totalSum = 0;
        for(int i = 0 ; i < n ; i++){
            totalSum += nums[i];
        }
        
        int minSubarray = negativeKadane(nums, n);
        
        if(totalSum == minSubarray){
            return case1;
            //edge case handle--> when all the numbers in the array are negative, therefore 
            //Just one to pay attention:
            // If all numbers are negative, case1 = max(A) and minSubarray = sum(A).
            //Now since the whole array is negative numbers, therefore case1 would also be a 
            //negative number
            
            // therefore In this case, max(maxSum, total - minSum) = 0, which means the sum of an 
            //empty subarray.
            // According to the deacription, We need to return the max(A), instead of sum of am 
            //empty subarray.
            // So we return the maxSum (case1) to handle this corner case.
            
            
            
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