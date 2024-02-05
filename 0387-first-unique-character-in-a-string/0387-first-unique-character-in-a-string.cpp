class Solution {
public:
    int firstUniqChar(string &s) {
        vector<int> freq(26);
        
        for(auto &x : s){
            freq[x-'a']++;
        }
        
        for(int i = 0 ; i < s.size() ; i++){
            auto x = s[i];
            if(freq[x-'a'] == 1){
                return i;
            }
        }
        return -1;
        
    }
};