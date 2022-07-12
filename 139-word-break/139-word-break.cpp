class Solution {
public:
    vector<int> memo;
    bool helper(string &s, unordered_set<string> &dictonary, int indx){
        if(indx == s.size()){
            return true;
        }
        
        if(memo[indx] != -1){
            return memo[indx];
        }
        
        for(int i = indx ; i < s.size() ; i++){
            string temp = s.substr(indx, i - indx +1);
            if(dictonary.find(temp) != dictonary.end()){
                // found our current substring in our dictionary
                // therefore we'll leave the aage ka part to recursion
                
                if(helper(s, dictonary, i +1)){
                    return memo[indx] = true;
                }
            }
        }
        
        return memo[indx] = false;
    }
    
    bool wordBreak(string &s, vector<string>& wordDict) {
        
        // put wordDict in map for faster access /trivial of a word from the dictonary
        
        unordered_set<string> dictonary(wordDict.begin(), wordDict.end());
        
        int n = s.size();
        memo.resize(n, -1);
        return helper(s, dictonary, 0);
        
    }
};