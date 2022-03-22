class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
     
        // TC - O(N), SC - O(N)
        
//         int n = nums.size();
//         vector<int> rightMin(n+1, -1);
        
//         rightMin[n] = INT_MAX;
        
//         for(int i = n-1 ; i >= 0 ; i--){
//             rightMin[i] = min(rightMin[i+1], nums[i]);
//         }
        
//         int leftMax = -1;
//         int chunkCount = 0;
        
//         for(int i = 0 ; i < n ; i++){
//             leftMax = max(leftMax, nums[i]);
//             if(leftMax <= rightMin[i+1]){
//                 chunkCount++;
//             }
//         }
        
//         return chunkCount;
        
        
        
        
        
        // TC - O(nlogn), sc - O(1)
        
        int n = nums.size();
        
        vector<int> v = nums;
        sort(v.begin(), v.end());
        
        long long s1 = 0;
        long long s2 = 0;
        int chunkCount = 0;
        
        for(int i = 0 ; i < n ; i++){
            s1+=nums[i];  // unsorted array sum
            s2+=v[i];     // sorted array sum
            if(s1==s2){
                chunkCount++;
            }
        }
        
        return chunkCount;
        
    }
};