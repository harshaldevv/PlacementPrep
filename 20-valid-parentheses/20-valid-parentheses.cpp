class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        
        if(len%2 != 0){
            return false;
        }
        
        stack<char> st;
        
        for(int i = 0 ; i < len ; i++){
            // cout << "i = " << i << endl;
            if(st.empty()){
                st.push(s[i]);
            }
            else if(st.top() == '(' && s[i] == ')' || st.top() == '[' && s[i] == ']' || st.top() == '{' && s[i] == '}' ){
                st.pop();
                continue;
            }
            else{
                st.push(s[i]);
            }
            
        }
        
        
        
        if(st.size() != 0){
            return false;
        }
        else{
            return true;
        }
    }
};