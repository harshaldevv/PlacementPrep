class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
//         vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        
//         int maxLen = 0;
        
//         for(int i = 1 ; i <= n1 ; i++){
//             for(int j = 1 ; j <= n2 ; j++){
//                 if(nums1[i-1] == nums2[j-1]){
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                     maxLen = max(maxLen, dp[i][j]);
//                 }
//                 else{
//                     dp[i][j] = 0;
//                 }
//             }
//         }
        
//         return maxLen;
        
        
        vector<int> curr (n2+1, 0);
        vector<int> prev (n2+1, 0);
        
        int maxLen = 0;
        
        for(int i = 1 ; i <= n1 ; i++){
            for(int j = 1 ; j <= n2 ; j++){
                if(nums1[i-1] == nums2[j-1]){
                    curr[j] = 1 + prev[j-1];
                    maxLen = max(maxLen, curr[j]);
                }
                else{
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
        
        return maxLen;
        
    }
};