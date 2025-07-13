class Solution {
public:
    bool isPal(string &s){
        int i = 0;
        int j = s.size() -1;

        while(i < j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
    
    void f(int start, string &str, vector<string> &holder, vector<vector<string>> &ans){
        if(start >= str.size()){
            ans.push_back(holder);
            return ;
        }
        
        
        for(int i = start; i < str.size(); i++){
            string myStr = str.substr(start, i - start +1);

            bool firstHalfIsPalindrome = isPal(myStr);
            if(firstHalfIsPalindrome){
                holder.push_back(myStr);
                
                // only now look to find more
                f(i+1, str, holder, ans);

                holder.pop_back();
            }
        }

        return;
    }

    vector<vector<string>> partition(string &s) {

        vector<vector<string>> ans;
        vector<string> holder;
        if(s.size() == 0){
            return ans;
        }

        string temp = "";
        f(0, s, holder, ans);
        
        return ans;
        
    }
};