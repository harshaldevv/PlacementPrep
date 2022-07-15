class Solution {
public:
    void helper(int open, int close, string &holder, vector<string> &ans){
        cout << "open, close = " << open << " , " << close << endl;
        if (open == close && open == 0 && close == 0 ){
            // stopping condition
            ans.push_back(holder);
            return ;
        }
        
        if(open < 0 ){
            return ;
        }
        
        if(open == close){
            holder.push_back('(');
            helper(open-1, close, holder, ans);
            holder.pop_back();
        }
        else if(open > close){
            // ye toh hoga hi nahi condition, bcz we are always using up 
            // an open bracket
        }
        else if(open < close){
            // now we have to 2 options -> either insert open bracket or insert
            // a closing brakcet
            
            // insert an opening bracket
            holder.push_back('(');
            helper(open-1, close, holder, ans);
            holder.pop_back();
            
            // insert an closing bracket
            holder.push_back(')');
            helper(open, close-1, holder, ans);
            holder.pop_back();
            
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
        
        int openBrackets = n;
        int closeBrackets = n;
        vector<string> ans;
        string holder = "";
        
        helper(openBrackets, closeBrackets, holder, ans );
        return ans;
    }
};