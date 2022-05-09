class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        unordered_set<int> s(nums1.begin(), nums1.end());
        
        vector<int> v;
        
        for(int i = 0 ; i < nums2.size() ; i++){
            int x = nums2[i];
            if(s.count(x)){
                v.push_back(x);
                s.erase(x);
            }
        }
        
        return v;
    }
};