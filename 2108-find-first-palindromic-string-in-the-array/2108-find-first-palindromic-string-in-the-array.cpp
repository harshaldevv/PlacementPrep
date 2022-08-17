class Solution {
public:
    bool isPalin(string &s){
        int l = 0;
        int r = s.size() -1;
        
        while(l<=r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto w : words){
            if(isPalin(w)){
                return w;
            }
        }
        
        return "";
    }
};