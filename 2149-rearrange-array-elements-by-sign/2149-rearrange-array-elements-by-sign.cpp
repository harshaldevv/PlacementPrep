class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> ans(n, -1);
        
        int positivePointer = 0;
        
        int vectorIndex = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] >= 0){
                ans[vectorIndex] = nums[i];
                vectorIndex +=2;
            }
        }
        
        vectorIndex = 1;
        
        for(int i = 0 ; i < n; i++){
            if(nums[i] < 0){
                ans[vectorIndex] = nums[i];
                vectorIndex +=2;
            }
        }
        
        return ans;
            
        
    }
};