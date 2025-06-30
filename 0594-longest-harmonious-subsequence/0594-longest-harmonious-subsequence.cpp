class Solution {
public:
    int findLHS(vector<int>& nums) {

        unordered_map<int, int> mp;

        for(auto &x : nums){
            mp[x]++;
        }

        int maxLen = 0;

        for(int i = 0 ; i < nums.size() ; i++){

            int x = nums[i]; // current element;

            int freq_x = mp[x];

            if(mp.find(x-1) != mp.end()){
                // x-1 exits
                maxLen = max(maxLen,  mp[x]  + mp[x-1]);
            }

            if(mp.find(x+1) != mp.end()){
                // x+1 exits
                maxLen = max(maxLen,  mp[x]  + mp[x+1]);
            }
        }

        return maxLen;
        
    }
};