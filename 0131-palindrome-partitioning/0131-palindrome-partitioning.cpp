class Solution {
public:
    bool isPal(string &s, int l, int r){
        while(l<r){
            if(s[l] != s[r]){
                return false;
            }
            else{
                l++;
                r--;
            }
        }
        return true;
    }
    
    void helper(int i, vector<string> &holder, vector<vector<string>> &ans, string &s){
        if(i >= s.size()){
            ans.push_back(holder);
            return ;
        }
        
        for(int j = i ; j < s.size() ; j++){
            if(isPal(s, i, j)){
                string temp = s.substr(i, j-i+1);
                holder.push_back(temp);
                helper(j+1, holder, ans, s);
                holder.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> holder;
        
        int i = 0;
        helper(i, holder, ans, s);
        
        return ans;
        
        
    }
};