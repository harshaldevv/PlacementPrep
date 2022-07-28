class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // Brute force --> O(nlogn)
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
        
//         return s==t;
        
        
        
        // O(n) solution , tc , sc = O(n)
        
        if(s.length() != t.length() ){
            return false;
        }
        
        int n = s.length() ;
        
        unordered_map<char, int> mp;
        
        for(int i = 0 ; i < n ; i++){
            mp[s[i]]++;
        }
        
        for(int i = 0 ; i < n ; i++){
            mp[t[i]]--;
        }
        
        for(auto it : mp){
            if(it.second > 0){
                return false;
            }
        }
        
        return true;
        
        
    }
};