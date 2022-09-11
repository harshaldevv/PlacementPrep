class Solution {
public:
    
    void solve(int open, int close, string &holder, vector<string> &ans){
        
        if(open < 0){
            return ;
        }
        if(close < 0){
            return ;
        }
        if(open == 0 && close == 0){
            ans.push_back(holder);
            return ;
        }
        
        
        // case I 
        if(open == close){
            holder.push_back('(');
            open--;
            solve(open, close, holder, ans);
            holder.pop_back();
        }
        else{
            // unequal hai open and close
            // 2 cases ---> solve(open -1, close) & solve(open, close -1);
            
            holder.push_back('(');
            solve(open -1, close, holder, ans);
            
            holder.pop_back();
            
            holder.push_back(')');
            solve(open, close-1, holder, ans);
            
            holder.pop_back();
            
        }
        
        return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string holder = "";
        int open = n;
        int close = n;
        
        solve(open, close, holder, ans);
        
        return ans;
        
    }
};