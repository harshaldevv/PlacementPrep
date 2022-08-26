class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // basically we check if nums[i] is our "val" or not.
        // If it is not, we place it in the array at posn "k".
        // now k is a pinter which maintains where we will place our number
        // kaise number, kya number, usse "k" ko farak nahi padta.
        // "k" bas jagah define karta. hamari condition ye hai ki
        // jaise hume koi number[i] != "val" milega, hum usko "k" pe place kar denge
        // and increment kar denge.
        // Khatam
        
        // TC - O(n), SC - O(1)
        
        int k = 0;
        int n = nums.size();
        
        for(int i = 0 ; i < n ; i++){
            
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }
        
        return k;
        
    }
};