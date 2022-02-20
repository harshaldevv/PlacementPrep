class Solution {
public:
    int longestCommonSubsequence(string X, string Y) {
        
        int n = X.size();
        int m = Y.size();
        
        int t[n+1][m+1];
        
        for(int i = 0 ; i < n+1 ; i++){
            t[i][0] = 0;
        }
        
        for(int j = 0 ; j < m+1 ; j++){
            t[0][j] = 0;
        }
        
        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 1 ; j < m+1 ; j++){
                if(X[i-1] == Y[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max (t[i][j-1], t[i-1][j]);
                }
            }
        }
        
        return t[n][m];

        
        
        // memoized gives TLE at test case 42
//         int n = text1.size();
//         int m = text2.size();
        
//         if( n<= 0 || m <= 0){
//             return 0;
//         }
        
//         vector<vector<int>> t( n+1 , vector<int>(m+1, -1));
        
//         return lcsHelper(text1, text2, n, m, t);
        
    }
    
    int lcsHelper(string x, string y, int n, int m , vector<vector<int>> &t){
        if(n <=0 || m <= 0){
            return 0;
        }
        
        if(t[n][m] != -1){
            return t[n][m];
        }
        
        if(x[n-1] == y[m-1]){
            t[n][m] = 1 + lcsHelper(x,y,n-1,m-1, t);
            return t[n][m];
        }
        else{
            t[n][m] = max(lcsHelper(x,y, n, m-1, t) , lcsHelper(x,y, n-1, m , t));
            return t[n][m];
        }
        
        
    }
};