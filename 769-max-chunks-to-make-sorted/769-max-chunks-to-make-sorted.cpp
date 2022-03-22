class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        
        // pehli baat toh ye identify that 
        // we need nums[i] at i-th posn
        // we could say so , bcz numbers hi hamare 0 to n-1 tak hai
        // and to make sorted array, we need ith number at ith posm
        
        int n = nums.size();
        
        int chunkCount = 0;
        int maxIndex = 0;
        
        for(int i = 0 ; i < n ;i++){
            maxIndex = max(maxIndex, nums[i]);
            if(i== maxIndex){
                chunkCount++;
            }
        }
        
        return chunkCount;
        
        
    }
};