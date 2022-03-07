class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // Another one pass solution --> the authentic one which is taught on YT and seen on 
        // leetcode discussion
        
        
        
        
        
        //one pass  --> optimizing the two passes into one pass 
        
        int n = nums.size();
        
        int forwardPro = 1;
        int reversePro = 1;
        
        int forwardMaxProduct = INT_MIN;
        int reverseMaxProduct = INT_MIN;
        
        for(int i = 0 ; i < n ; i++){
            
            // i --> forward ptr
            
            int j = n-1-i;  //  j --> reverse ptr
            
            int x = nums[i];
            forwardPro*=x;
            forwardMaxProduct = max( forwardPro , forwardMaxProduct);
            if(forwardPro==0){
                forwardPro = 1;
            }
            
            
            
            
            int y = nums[j];
            reversePro*=y;
            reverseMaxProduct = max( reversePro, reverseMaxProduct);
            
            if(reversePro == 0){
                reversePro = 1;
            }
            
             
        }
        
        return max( forwardMaxProduct, reverseMaxProduct);
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         //
//         //Below is the 2 pass solution -->TC : O(n), Sc : O(1)
//         int n = nums.size();
        
//         int pro = 1;
//         int maxPro = INT_MIN;
        
//         //forward pass --> first pass
//         for(int i = 0 ; i < n ; i++){
            
//             int x = nums[i];
//             pro*= x;
//             maxPro = max(maxPro, pro);
//             if(pro == 0){
//                 pro = 1;
//             }
            
//         }
        
        
        
//         pro = 1;
        
//         //reverse pass --> second pass
//         for(int i = n-1 ; i >= 0 ;i--){
//             pro*=nums[i];
//             maxPro = max(pro, maxPro);
//             if(pro == 0){
//                 pro=1;
//             }
//         }
        
//         return maxPro;
        
        
    }
};