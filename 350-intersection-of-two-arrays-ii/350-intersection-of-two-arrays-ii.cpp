class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        unordered_map<int, int> mp;
        
        for(auto x : nums1){
            mp[x]++;
        }
        
        vector<int> v;
        
        for(int i = 0 ; i< nums2.size() ; i++){
            if(mp[nums2[i]] >0){
                v.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        
        return v;
    }
};