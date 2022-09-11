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
            // only one case possible here
            holder.push_back('(');
            solve(open-1, close, holder, ans);
            holder.pop_back();
        }
        else{
            // unequal hai open and close
            // 2 cases ---> solve(open -1, close) & solve(open, close -1);
            
            // insert a opening bracket
            holder.push_back('(');
            solve(open -1, close, holder, ans);
            holder.pop_back(); // backtrack
            
            
            // insert a closing bracket
            holder.push_back(')');
            solve(open, close-1, holder, ans);
            holder.pop_back(); // backtrack
            
        }
        
        return ;
    }
    vector<string> generateParenthesis(int n) {
        
        // jab bhi close > open --> we get 2 choices --> ie closing wali choice bhi mil rahi hai
        // why -? Open ka bracket hoga tabhi toh close ka brakcet lagaoge.
        
        // if open == close --> we only get the open wali choice. close bracket wali choice 
        // nahi hai. Whyso ? Becuase if we use a close brcket, then after using that 
        // closed bracket we'll get an unbalanced string (right after) we've used 
        // the closing brakcet, which is an undesirable output/situation. 
            
        vector<string> ans;
        string holder = "";
        int open = n;
        int close = n;
        
        solve(open, close, holder, ans);
        
        return ans;
        
    }
};