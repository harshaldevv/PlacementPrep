class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        unordered_map<int, int> mp2;
        
        int n = nums.size();
        
        vector<int> ans;
        
        for(int i = 0 ; i < n; i++){
        
            mp[nums[i]]++;
            
            // cout << mp[nums[i]] << endl;
            // if(mp[nums[i]] > n/3){
            //     ans.push_back(nums[i]);
            // }
        }
        
        for( auto it : mp){
            if(it.second > n/3){
                mp2[it.first]++;
            }
        }
        
        
        for(auto it : mp2){
            ans.push_back(it.first);
        }
        return ans;
        
    }
};