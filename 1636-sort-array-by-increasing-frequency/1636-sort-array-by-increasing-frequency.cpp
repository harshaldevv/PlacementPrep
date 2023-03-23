class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        
        for(auto &x :nums){
            mp[x]++;
        }
        
        
        sort(nums.begin(), nums.end(), [&](auto &a, auto &b) -> bool{
            if(mp[a] == mp[b]){
                return a > b;
            }
            else{
                return mp[a] < mp[b];
            }
        });
        
        return nums;
    }
};