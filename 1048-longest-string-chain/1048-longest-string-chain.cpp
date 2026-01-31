class Solution {
public:

    bool checkWord(string &currWord, string &prevWord){
        // currWord -> bigger word
        // prevWord -> smaller word
        
        // first check the size
        if(currWord.size() - prevWord.size() != 1){
            return false;
        }

        for(int i = 0 ; i < currWord.size() ; i++ ){
            string p1 = currWord.substr(0, i);
            string p2 = currWord.substr(i+1, currWord.size() - (i+1));
            string newWord = p1+p2;
            if(newWord == prevWord){
                return true;
            }
        }
        return false;
    }

    int longestStrChain(vector<string>& words) {

        // sort by length
        sort(words.begin(), words.end(), [](string &s1, string &s2){
            return s1.size() < s2.size();
        });

        int n = words.size();
        vector<int> dp(n+1, 1);
        int ans = 1;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(checkWord(words[i], words[j])){
                    dp[i] = max(1+ dp[j], dp[i]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }

};