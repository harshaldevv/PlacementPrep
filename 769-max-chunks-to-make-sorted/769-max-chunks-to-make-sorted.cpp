class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        
        // 768. Max Chunks To Make Sorted II --> this is better 
        
        // pehli baat toh ye identify that 
        // we need nums[i] at i-th posn
        // we could say so , bcz numbers hi hamare 0 to n-1 tak hai
        // and to make sorted array, we need ith number at ith posm
        
//         int n = nums.size();
        
//         int chunkCount = 0;
//         int maxIndex = 0;
        
        
//         for(int i = 0 ; i < n ;i++){
//             maxIndex = max(maxIndex, nums[i]);
//             if(i== maxIndex){
//                 chunkCount++;
//             }
//         }
        
//         return chunkCount;
        
        
        
        
        
    // another attempt
        int n = nums.size();
        long long s1 = 0;
        long long s2 = 0;
        int chunk = 0;
        for(int i = 0 ; i < n ; i++){
            s1+=nums[i];  // unsorted array sum
            s2+=i;        //   sorted array sum
            if(s1==s2){
                chunk++;
            }
        }
        
        return chunk;
        
    }
};