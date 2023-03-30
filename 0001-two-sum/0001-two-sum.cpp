class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //hci research
        unordered_map<int, int> hash_map;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (hash_map.find(complement) != hash_map.end()) {
                result.push_back(hash_map[complement]);
                result.push_back(i);
                break;
            }

            hash_map[nums[i]] = i;
        }

        return result;
    }
};
