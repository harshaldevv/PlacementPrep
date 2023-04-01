class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = INT_MIN;
        int sum = 0;
        
        for(int i = 0 ; i< nums.size() ; i++){
            int x = nums[i];
            
            sum += x;
            
            maxSoFar = max(sum, maxSoFar);
            
            if(sum < 0 ){
                sum = 0;
            }
            
        }
        
        return maxSoFar;
        
    }
};