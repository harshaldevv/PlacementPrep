class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map <int, int> mp;
        
        int freq = -1;
        int numb = INT_MIN;
        
        for(int i = 0 ; i < nums.size();i++ ){
            mp[nums[i]]++;
            
            int internal_freq = mp[nums[i]];
            if(internal_freq > freq){
                freq = internal_freq;
                numb = nums[i];
            }
        }
        
        return numb;
        
        
        // for (auto& it: mp) {
        //     // Do stuff
        //     // cout << it.first;
        //     if(it.second > freq){
        //         freq = it.second;
        //         numb = it.first;
        //     }
        // }
        
        return numb;
        
    }
};