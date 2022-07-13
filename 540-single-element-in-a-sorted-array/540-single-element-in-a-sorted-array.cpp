class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // pls do this in logn pls
       if(nums.size() == 1){
           return nums[0];
       }
        
        int l = 0;
        int r = nums.size() -1;
        
        while(l<= r){
            int mid = l + (r-l)/2;
            
            if(mid%2 != 0 && nums[mid] == nums[mid-1] || mid%2 == 0 && nums[mid] == nums[mid+1]){
                // go right
                l = mid +1;
            }
            else{
                r = mid -1;
            }
        }
        
        return nums[l];
        
        
        
        
        
        
//         // linear search
//         for(int i= 0 ; i < nums.size()-1;i+=2){
//             if(nums[i] != nums[i+1]){
//                 return nums[i];
//             }
//         }
//         return nums[nums.size()-1]; // warna phir ab last element hu hoga hamara ans
        
        
//         // XOR SOLUTION
//         // We can use the property of xor operation in this problem. We know that a ⊕ a = 0, 
//         // i.e, two same numbers when xor-ed, cancels each other out. In our case, every element 
//         // occurs twice except the one. Thus, if we xor all the elements from nums, every 
//         // element will cancel each other out except the required answer.
//         int ans = 0;
        
//         for(auto x : nums){
//             ans^=x;
//         }
//         return ans;
    }
};