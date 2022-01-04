class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map <int, int> mp;
        
        for(int i = 0 ; i < nums.size();i++ ){
            mp[nums[i]]++;
        }
        
        int freq = -1;
        int numb = INT_MIN;
        
        for (auto& it: mp) {
            // Do stuff
            // cout << it.first;
            if(it.second > freq){
                freq = it.second;
                numb = it.first;
            }
        }
        
        return numb;
        
    }
};