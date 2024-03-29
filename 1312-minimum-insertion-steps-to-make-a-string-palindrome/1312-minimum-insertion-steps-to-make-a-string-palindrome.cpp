class Solution {
    int LCS(string X, string Y){
        int n = X.size();
        int m = Y.size();
        
        int t[n+1][m+1];
        
        for(int i = 0 ; i < n+1 ; i++){
            t[i][0] = 0;
        }
        
        for(int j = 0 ; j < m+1 ; j++){
            t[0][j] = 0;  
        }
        
        
        for(int i = 1 ; i < n+1 ; i ++){
            for(int j = 1 ; j <m+1 ; j++){
                if(X[i-1] == Y[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
                }
            }
        }
        
        return t[n][m];
        
        
    }
public:
    int minInsertions(string s) {
        
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        return s.size() - LCS(s, rev);
        
    }
};