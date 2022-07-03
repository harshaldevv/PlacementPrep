class Solution {
public:
    
    string getLCS(string &X, string &Y, int n, int m){
        int t[n+1][m+1];
        
        memset(t, 0, sizeof(t));
        
        // initlaize first row and col with zero
        
        for(int i =1 ; i < n+1 ; i++){
            for(int j = 1; j <m+1 ; j++){
                if(X[i-1] == Y[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        
        // return t[n][m];
        
        
        int i = n;
        int j = m;
        
        string ans = "";
        
        while(i>0 && j >0){
            if(X[i-1] == Y[j-1]){
                ans.push_back(X[i-1]);
                i--;
                j--;
            }
            else{
                if(t[i-1][j] > t[i][j-1]){
                    ans.push_back(X[i-1]);
                    i--;
                }
                else{
                    ans.push_back(Y[j-1]);
                    j--;
                }
            }
        }
        
        // characters in s1 still left
        while(i>0){
            ans.push_back(X[i-1]);
            i--;
        }
        
        while(j>0){
            ans.push_back(Y[j-1]);
            j--;
        }
        
        reverse(ans.begin(), ans.end());
        
        
        return ans;
        
        
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n = str1.size();
        int m = str2.size();
        
        // return m+n-LCS; --> basic idea --> str1 + str2 - LCS(str1, str2);
        
        string ans = getLCS(str1, str2, n,m);
        
        return ans;
        
        
        
    }
};