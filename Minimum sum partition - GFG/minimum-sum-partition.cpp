//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	    // Your code goes here
	    
	    int s = 0;
        
        for(int i = 0 ; i < n ; i++){
            int x = nums[i];
            s+=x;
        }
        
        bool dp[n][s+1000];
        memset(dp, false, sizeof(dp));
        
        // cout << "s = " << s << endl;
        
        for(int i = 0 ; i < n ; i++){
            dp[i][0] = true;
        }
        
        
        
        dp[0][nums[0]]  = true;    
        
        
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j <=s ; j++ ){
                
                bool notTake = dp[i-1][j];
        
                bool take = false;

                if(j >= nums[i]){
                    take = dp[i-1][j - nums[i]];
                }

                dp[i][j] = notTake | take;
                
            }
        }
        
        
        
        // find true in the last row from right to left.
        
        int maxS1 = 0;
        for(int j = s/2  ; j >=0 ; j--){
            if(dp[n-1][j] == true){
                maxS1 = j;
                break;
            }
        }
        
        // cout << "maxS1 = " << maxS1 << endl;
        
        return abs(s - 2*maxS1);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends