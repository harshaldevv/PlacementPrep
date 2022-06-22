class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        // TC - O(n), SC - O(1)
        int right = 0;
        for(auto x : nums){
            right +=x;
        }
        int left = 0;
        for(int i = 0 ; i < n ; i++){
            right-=nums[i];
            if(left == right){
                return i;
            }
            left+=nums[i];
            
        }
        
        // TC - O(n), SC- O(n)
//         vector<int> left(n);
//         vector<int> right(n);
        
//         int l = 0;
//         int r = 0;
//         for(int i = 0 ; i < n ; i++){
//             l+=nums[i];
//             r+=nums[n-1-i];
//             left[i] = l;
//             right[n-1-i] = r;
        
//         }
        
//         for(int i = 0 ; i < n ; i++){
//             if(left[i] == right[i]){
//                 return i;
//             }
//         }
        
        return -1;
    }
};