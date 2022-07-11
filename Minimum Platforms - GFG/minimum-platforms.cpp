// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	/*
    	Just think yourself as a station master, and you just care 
    	how many came and how many went. Not when one came and when went
    	*/
    	
    	sort(arr, arr+n);
    	sort(dep, dep + n);
    	
    	int i = 1;
    	int j = 0;
    	
    	int count = 1;  // this counts the number of occupied platforms at this instant
    	int ans = 1;  // this count the number of max platforms we require
    	// where max platforms would be max of occupied platforms at any instant
    	// therefore we keep ans = max(ans, count), so that incase our count > ans
    	// at any point of time, we increment our ans.
    	
    	
    	
    	while(i < n && j < n){
    	    if(arr[i] <= dep[j]){
    	        count++;
    	        i++;
    	    }
    	    else{
    	        count--;
    	        j++;
    	    }
    	    
    	    ans = max(ans, count);
    	}
    	
    	return ans;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends