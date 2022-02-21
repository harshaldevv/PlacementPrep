class Solution {
    int LCS(string x, string y){
        int n = x.size();
        int m = y.size();
        
        int t[n+1][m+1];
        
        for(int i = 0 ; i < n+1 ; i++){
            t[i][0] = 0;
        }
        
        for(int j = 0 ; j < m+1 ; j++){
            t[0][j] = 0;
        }
        
        for(int i = 1 ; i < n+1 ;i++){
            for(int j = 1 ; j < m+1 ; j++){
                if(x[i-1] == y[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        
        return t[n][m];
    }
public:
    int minDistance(string word1, string word2) {
        
        return word1.size() + word2.size() - 2*LCS(word1, word2);
    }
};