class Solution {
public:
    void helper(vector<string> &ans, string &holder, int n , int open, int close){
        
        if(open < 0 || close < 0){
            return ;
        }
        if(open == 0 && close == 0 ){
            ans.push_back(holder);
            return ;
        }
        
        if(open == close){
            holder += "(";
            helper(ans, holder, n, open-1, close);
            holder.pop_back();
        }
        else if(open < close ){
            // 2 choices here
            
            holder+= "(";
            helper(ans, holder, n, open-1, close);
            holder.pop_back();
            
            holder += ")";
            helper(ans, holder, n, open, close-1);
            holder.pop_back();
            
        }
        else if(open > close){
            //case not possible
            return ;
        }
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        string holder = "";
        
        int open = n;
        int close = n;
        
        helper(ans, holder, n, open, close);
        
        return ans;
        
    }
};