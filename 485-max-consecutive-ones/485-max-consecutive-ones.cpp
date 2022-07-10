class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int l = 0;
        int r = 0;
        int n = nums.size();
        int ans = 0;
        while(r < n){
            if(nums[r] == 0){
                
                r++;
                l = r;
            }
            else{
                // nums[i] = 1 toh ho hi raha hai toh hume kuch karne ki zaroorat nahi hai
                
                ans = max(ans, r - l+1);
                r++;
            }
        }
        
        return ans;
        
        
        
        
        
        
        
        
        
//         int l = 0;
//         int r = 0;
//         int n = nums.size();
//         int ans = 0;
//         while(r < n){
//             if(nums[r] == 1){
//                 ans = max(ans, r - l +1);
//                 r++;
//             }
//             else{
//                 r++;
//                 l = r;
//             }
//         }
        
//         return ans;
        
    }
};