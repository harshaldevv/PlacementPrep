class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<long long> st;
        
        for(int i = 0 ; i < tokens.size() ; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*" ){
                
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                
                auto op = tokens[i];
                
                if(op == "+"){
                    st.push(a+b);
                }
                else if(op == "-"){
                    st.push( b-a );
                }
                else if(op == "*"){
                    // cout << "here" << endl;
                    st.push((long long)a*b);
                }
                else if(op == "/"){
                    st.push(b/a);
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        
        return st.top();
        
    }
};