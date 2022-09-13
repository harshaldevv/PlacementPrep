class Solution {
public:
    string frequencySort(string s) {
        
        // string ans = "";
        
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