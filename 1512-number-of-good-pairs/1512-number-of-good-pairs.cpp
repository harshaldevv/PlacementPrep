class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
//         int count = 0;
//         for(int i = 0 ; i < nums.size(); i++){
//             for(int j = i+1 ; j < nums.size() ; j++){
//                 if(nums[i] == nums[j]){
//                     count++;
//                 }
//             }
//         }
        
        
//         return count;
        
        // HINT - > https://leetcode.com/problems/number-of-good-pairs/discuss/1457646/JAVA-or-STORY-BASED-or-0ms-or-SINGLE-PASS-or-EASY-TO-UNDERSTAND-or-SIMPLE-or-HASHMAP
        
        int n = nums.size();
        // int mp[101] = {};
        unordered_map<int, int> mp;
        
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            
            int x = mp[nums[i]];
            ans+=x;
            mp[nums[i]]++;
            
        }
        
        return ans;
    }
};