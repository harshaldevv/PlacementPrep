class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> rightMin(n+1, -1);
        
        rightMin[n] = INT_MAX;
        
        for(int i = n-1 ; i >= 0 ; i--){
            rightMin[i] = min(rightMin[i+1], nums[i]);
        }
        
        int leftMax = -1;
        int chunkCount = 0;
        
        for(int i = 0 ; i < n ; i++){
            leftMax = max(leftMax, nums[i]);
            if(leftMax <= rightMin[i+1]){
                chunkCount++;
            }
        }
        
        return chunkCount;
        
    }
};