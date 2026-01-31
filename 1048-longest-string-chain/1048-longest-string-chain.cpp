class Solution {
public:
    bool checkWord(string &currWord, string &lastWord){

        // now we will start deleting char from currWord, to see if they match up to lastWord
        for(int i = 0 ; i < currWord.size(); i++){
            string p1 = currWord.substr(0, i);
            string p2 = currWord.substr(i+1, currWord.size() - i - 1);

            string wordToCheck = p1+ p2;

            if(wordToCheck == lastWord){
                return true;
            }
        }

        return false;
    }

    int f(int i, int j, vector<string> &words, vector<vector<int>> &dp){
        // i = curr word index (bigger)
        // j = last word index (smaller)

        if( i >= words.size() ){
            return 0;
        }

        if(dp[i][j+1] != -1){
            return dp[i][j+1];
        }

        int notake = f(i+1, j, words, dp);

        // take
        int take = 0;
        if(j == -1 || words[i].size() - words[j].size() == 1 && checkWord(words[i], words[j])){
            take = 1 + f(i+1, i, words, dp);
        }

        return dp[i][j+1] = max(take, notake);

    }

    int longestStrChain(vector<string>& words) {
        // sort words length wise
        
        sort(words.begin(), words.end(), [](string &s1, string &s2){
            return s1.size() < s2.size();
        });

        // LIS -> 0th index se start hoga

        int n = words.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(0, -1, words, dp);


        
    }
};