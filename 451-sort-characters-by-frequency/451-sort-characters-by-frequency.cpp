class Solution {
public:
    string frequencySort(string s) {
        
        // Learnt how to do custom sort in this question, therefore implemented the same here
        // HITESH OP
        // https://leetcode.com/problems/sort-array-by-increasing-frequency/
        
        unordered_map<char, int> mp;
        
        for(auto &c : s) {
            mp[c]++;
        }
        
        sort(s.begin(), s.end(), [&mp](auto &a, auto &b) -> bool{
           if(mp[a] == mp[b]) {
               return a < b;
           }
            else{
                return mp[a] > mp[b];
            }
        });
        
        return s;
        
    }
};