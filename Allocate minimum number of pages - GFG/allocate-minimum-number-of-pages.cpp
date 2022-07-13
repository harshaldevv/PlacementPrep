// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    bool ispossible(int mid, int A[], int n, int k){
        int sum = 0;
        
        int kids = 1;
        
        for(int i = 0 ; i < n ; i++){
            sum += A[i];
            if(sum > mid){
                kids++;
                sum = A[i];
            }
            
            if(kids > k){
                return false;
            }
        }
        
        return true;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int k) 
    {
        //code here
        
        int start = 0;
        int end = 0;
        
        for(int i = 0 ; i < N ; i++){
            start = max(start, A[i]);
            end += A[i];
        }
        
        int ans = -1;
        while(start <= end){
            int mid = start + (end- start)/2;
            
            if(ispossible(mid, A, N, k )){
                //go left
                ans = mid;
                end = mid -1;
            }
            else{
                start = mid +1;
            }
        }
        
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends