class Solution {
public:
    
    void solve(string &digits, int i, vector<string> &ans, string &holder, vector<string> &mp){
        
        if(i >= digits.size()){
            ans.push_back(holder);
            return ;
        }
        
        auto t = mp[digits[i] - '0'];
        
        for(auto &x : t){
            holder.push_back(x);
            solve(digits, i +1, ans, holder, mp);
            holder.pop_back();
        }
        
        return ;

    }
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if(digits == ""){
            return ans;
        }
        string holder = "";
        
        
        vector<string> mp = {"#", "##", "abc", "def", "ghi", "jkl" , "mno", "pqrs", "tuv", "wxyz"};
        
        // cout << mp.size() << " blah" << endl;
        
        int i = 0;
        solve(digits, i, ans, holder, mp);
        
        return ans;
        
        
    }
};