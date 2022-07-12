class Solution {
public:
    void helper(string &s, unordered_set<string> &dicti, string path, vector<string> &ans, int indx){
        if(indx == s.size()){
            path.pop_back() ; // remove the trialing space 
            ans.push_back(path);
            return ;
        }
        
        for(int i = indx ; i < s.size() ; i++){
            string temp = s.substr(indx, i - indx +1);
            if(dicti.find(temp) != dicti.end()){
                // found temp in our dict
                helper(s, dicti, path + temp + " " , ans, i +1);                
            }
        }
        
        return ;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> dicti;
        for(auto word : wordDict){
            dicti.insert(word);
        }
        
        string path = "";
        vector<string> ans;
        
        helper(s, dicti, path, ans, 0);
        
        return ans;
        
    }
};