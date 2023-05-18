class Solution {
public:
    void helper(string &digits, string &holder, vector<string> &ans, vector<string> &phone, int i ){
        if(i == digits.size()){
            ans.push_back(holder);
            return;
        }
        
        auto t = digits[i] - '0';
        
        for(auto &x : phone[t]){
            holder.push_back(x);
            helper(digits, holder, ans, phone, i+1);
            holder.pop_back();
        }
        
        return ;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> phone {"#", "##", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        
        if(digits == ""){
            return ans;
        }
        
        string holder = "";
        int i = 0;
        helper(digits, holder, ans, phone, i);
        return ans;
        
    }
};