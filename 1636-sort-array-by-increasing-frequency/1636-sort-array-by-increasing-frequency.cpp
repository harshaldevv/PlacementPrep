class Solution {
public:
    
    
    
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        
        for(auto & x : nums){
            mp[x]++;
        }
        
        // vector<int> ans;
        
        // need a custom comparator cuz If multiple values have 
        // the same frequency, sort them in decreasing order.
        
        // min heap
        sort(nums.begin(), nums.end(), [&mp](auto &a, auto &b) -> bool {
            if(mp[a] == mp[b]){
                return a > b;
            }
            else{
                return mp[a]  < mp[b];
            }
        } );
                
            
            return nums;
    }
};