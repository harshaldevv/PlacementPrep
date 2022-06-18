// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    long long kSmallest(long long arr[], long long n, long long k){
        // max heap
        priority_queue<long long> maxheap;
        for(int i = 0 ; i < n ; i++){
            maxheap.push(arr[i]);
            if(maxheap.size() > k){
                maxheap.pop();
            }
        }
        
        return maxheap.top();
    }
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        long long first = kSmallest(A, N, K1);
        long long second = kSmallest(A, N, K2);
        
        long long sum = 0;
        for(int i = 0 ; i < N ; i++){
            if(A[i] > first && A[i] < second){
                sum+=A[i];
            }
        }
        
        return sum;
        
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends