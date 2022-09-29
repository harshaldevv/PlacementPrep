class Solution {
public:
    bool isValid(string s) {
        
        if(s.size() == 0){
            return true;
        }
        
        stack<char> st;
        
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(st.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}')){
                return false;
            }
            else if( !st.empty() && ( st.top() == '(' && s[i] == ')' || st.top() == '{' && s[i] == '}' || st.top() == '[' && s[i] == ']' ) ){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        
        return st.empty();
        
        
    }
};