class Solution {
public:
    void helper(string &s, int ind, vector<string> &holder, vector<vector<string>> &ans){
        if( ind == s.size()){
            ans.push_back(holder);
            return ;
        }
        for(int i = ind ; i <s.size() ; i++){
            // cout << "ind, i = " << ind << " , " << i << endl ;
            if(isPalindrome(s, ind, i )){
                auto temp = s.substr(ind, i - ind +1);
                // cout << "temp = " << temp << " , ind = " << ind << " , i = " << i << endl;
                holder.push_back(s.substr(ind, i - ind +1));
                helper(s, i+1, holder, ans);
                holder.pop_back(); // backtrack
            }
        }
        return ;
    }
    
    bool isPalindrome(string &s, int l, int r){
        while(l<= r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        
        if(s.size() == 0){
            return ans;
        }
        
        vector<string> holder;
        
        helper(s, 0, holder, ans);
        
        return ans;
        
    }
};