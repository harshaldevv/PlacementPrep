class Solution {
public:
    bool checkPal(string &s){
        int l = 0;
        int r = s.size() -1;
        
        while(l<=r){
            if(s[l] != s[r]){
                return false;
            }
            else{
                l++;
                r--;
            }
        }
        
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        
        for(int i = 0 ; i < words.size(); i++){
            string x = words[i];
            
            char s0 = x[0];
            char sLast = x[x.size() -1];
            
            if(s0 == sLast){
                //try to check for palindrome
                bool isPal = checkPal(x);
                if(isPal){
                    return x;
                }
            }
        }
        
        return "";
        
    }
};