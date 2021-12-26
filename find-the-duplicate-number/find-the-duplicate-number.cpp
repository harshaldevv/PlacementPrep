class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow!=fast);
        
        
        
//         while(slow != fast){
//             slow = nums[slow];
//             fast = nums[nums[fast]];
//         }
        
//         cout << fast << endl;
        
        
        fast = nums[0];
        // fast = 0;
        
        
        while(slow!= fast){
            slow = nums[slow];
            fast = nums[fast];
            
            cout << slow << " " << fast << endl;
        }
        
        return slow; // return fast --> either of them work
        
    }
};