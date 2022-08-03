class Solution {
public:
    
    void helper(vector<string> &ans, int i, string &s){
        
        // cout << "i = " << i << endl;
        
        if(i >= s.size()){
            ans.push_back(s);
            return ;
        }
        
        char c = s[i];
        
        if( !isdigit(c) && islower(c) ){
            // cout << "here , i = " << i << endl;
            
            // capitalize mat karo
            helper(ans, i+1, s);
            
            //capitalize kardo
            s[i] = toupper(s[i]);
            
            helper(ans, i+1, s);
            
            //backtrack
            s[i] = tolower(s[i]);
            
            
        }
        else if( !isdigit(c) && isupper(c)){
            
            // lower mat karo
            helper(ans, i+1, s);
            
            //lower kardo
            s[i] = tolower(s[i]);
            
            helper(ans, i+1, s);
            
            //backtrack
            s[i] = toupper(s[i]);
            
        }
        else{
            helper(ans, i+1, s);
        }
        
        return ;
        
    }
    vector<string> letterCasePermutation(string s) {
        
        vector<string> ans;
        string t = s;
        
        int i = 0;
        helper(ans, i, s);
        
        return ans;
        
    }
};