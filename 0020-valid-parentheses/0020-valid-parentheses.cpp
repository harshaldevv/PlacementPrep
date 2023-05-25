class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        unordered_map<char, char> mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        
        for(int i = 0 ; i < s.size() ; i++){
            
            if(st.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}')){
                return false;
            }
            
            
            if(s[i] == '(' || s[i] == '{' || s[i] == '[' ){
                st.push(s[i]);
            }
            else{
                char a = s[i];
                char b = st.top();
                
                if(a == ')' && b == '('  || a == '}' && b == '{' || a == ']' && b == '['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        
        if(st.size() > 0){
            return false;
        }
        
        
        return true;
        
    }
};