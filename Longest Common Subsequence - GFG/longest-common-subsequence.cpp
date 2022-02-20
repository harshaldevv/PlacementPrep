// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int> > t(x+1, vector<int>(y+1, -1));        
        return lcsHelper(s1, s2, x, y, t);
    }
    
    int lcsHelper(string x, string y, int n, int m,vector<vector<int>>& t){
        
        if(n <= 0 || n <=0 ){
            return 0;
        }
        
        if(t[n][m] != -1){
            return t[n][m];
        }
        
        
        
        if(x[n -1] == y[m - 1]){
            t[n][m] = 1 + lcsHelper(x,y,n -1,m -1, t);
            return t[n][m];
        }
        else{
            t[n][m] = max(lcsHelper(x,y,n-1,m,t) , lcsHelper(x,y,n,m-1,t) );
            return t[n][m];
        }
        
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends