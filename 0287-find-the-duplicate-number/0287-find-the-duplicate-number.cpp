class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Hashmap approach
        // TC- O(N)
        // SC - O(N)
        
        // Sum approach --> Sum of array - n(n+1)/2 , where n = nums.size() -1
        // here it fails on testcase -> [2,2,2,2,2]
        
        
        // Linked List approach --> cycle , slow fast
        
        int slow = nums[0];
        int fast = nums[0];
        
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                break;
            }
        }
        
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
        
    }
};