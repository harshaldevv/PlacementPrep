// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  bool isValid(int mid, int arr[], int n, int k){
      // mid represents time
      // k repesents the painters i have
      // n =  array size

      int t = 0; // time sum
      int p = 1; // painters
      
      for(int i = 0 ; i < n ; i++){
          t += arr[i];
          if(t > mid){
              p++;
              t = arr[i];
          }
          
          if(p > k){ // if i require more than k painterns
              return false;
          }
      }
      return true;
  }
    long long minTime(int arr[], int n, int k)
    {
        
        // code here
        // return minimum time
        int start = *max_element(arr, arr+n);
        int end = 10000000000;
        int res = -1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(isValid(mid, arr, n, k)== true){
                res = mid;
                end = mid-1;
            }
            else{
                start = mid +1;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends