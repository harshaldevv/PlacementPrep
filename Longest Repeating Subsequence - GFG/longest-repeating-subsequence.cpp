// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    
    int lcs(string x, string y){
        int n = x.size();
        int m = y.size();
        
        int t[n+1][m+1];
        
        for(int i = 0 ; i < n +1 ; i ++){
            t[i][0] = 0;
        }
        
        for(int j = 0 ; j < m+1 ; j ++){
            t[0][j] = 0;
        }
        
        
        for(int i =1 ; i < n+1 ;i++){
            for(int j = 1 ; j < m+1 ; j++){
                if(x[i-1] == y[j-1] && i!=j){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
                }
            }
        }
        
        return t[n][m];
    }
    
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    
		    return  lcs(str, str); // lcs but with variation in
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends