class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//      // TC - O(2n), SC - O(n)
//         int n = s.size();
//         unordered_set<char> SET;
        
//         int l = 0;
//         int r = 0;
//         int maxlen = 0;
        
//         while ( r <  n ){
//             if(SET.find(s[r]) == SET.end()){
//                 // not found in our set
                
//                 //push in set
//                 SET.insert(s[r]);
//                 maxlen = max(maxlen, r-l +1);
//                 r++;
//             }
//             else{
                
//                 SET.erase(s[l]);
//                 l++;
//             }
//         }
//         return maxlen;
        
        
        
        
        
        
        
        
        int n = s.size();
        unordered_map<char, int> mp;
        int maxlen = 0;
        
        int l = 0;
        int r = 0;
        
        while( r < n ){
            auto c = s[r];
            
            if(mp.find(c) != mp.end()){
                
                l = max(l, mp[c] +1);
            }
            
            mp[c] = r;
            maxlen = max(maxlen, r-l +1);
            
            r++;
        }
        
        return maxlen;
        
    }
};