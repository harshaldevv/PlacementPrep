class Solution {
public:
    void solve(int i, vector<string> &phone, string &digits,  string &path,vector<string> &ans){
        if(i==digits.size()){
            ans.push_back(path);
                return ;
        }
        
        for(auto &c : phone[digits[i] - '0']){
            path.push_back(c);
            solve(i+1, phone, digits, path, ans);
            path.pop_back(); // back track
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        
        vector<string> phone{"", "", "abc", "def", "ghi", "jkl", "mno","pqrs","tuv","wxyz"};
        
        

        vector<string> ans;
        if(digits.size() == 0){
            return ans;
        }
        string path = "";
        solve(0, phone, digits, path, ans);
        
        
        
        
        
        
        
        
        
        // backtracking khtm
        
        // YAHI 3 bach rahe hai, jaldi jaldi khtm kardo
        
        // trees (interviewbit poora)
        // graphs (dijsktra, all path algorithms, 0-1 BFS)
        // DP revise karna hai
        
        // 2 pointers / sliding window (aditya verma)
        
        
        
        
        
        return ans;
        
        
    }
};