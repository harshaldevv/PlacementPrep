// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    
	   // int start=1;
    // int end=m;
    // while(start<=end)
    // {
    //     int mid=(start+end)/2;
    //     if(pow(mid,n)==m)
    //     {
    //         return mid;
    //     }
    //     else if(pow(mid,n)>m)
    //     {
    //         end=mid-1;
    //     }
    //     else if(pow(mid,n)<m)
    //     {
    //         start=mid+1;
    //     }
         
    // }
    // return -1;
	    
	    
	    int l = 1;
	    int r = m;
	    
	    while(l<=r){
	        int mid = l + (r-l)/2;
	        if(pow(mid, n) == m){
	            return mid;
	        }
	        else if(pow(mid, n) > m){
	            // go left
	            r = mid-1;
	        }
	        else{
	            l = mid+1;
	        }
	    }
	    return -1;
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends