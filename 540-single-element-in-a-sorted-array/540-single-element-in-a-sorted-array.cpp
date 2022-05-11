class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // linear search
        for(int i= 0 ; i < nums.size()-1;i+=2){
            if(nums[i] != nums[i+1]){
                return nums[i];
            }
        }
        return nums[nums.size()-1]; // warna phir ab last element hu hoga hamara ans
        
        
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