// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        
        // iska trivial solutino kya hoga :/
        if( n <= 1){
            return  0;
        }
        // maintain min heap of size 2 (maintain rope length)
        // if size > 2 , pop out 2 elements,
        // add them
        // push then in heap
        priority_queue<long long, vector<long long>, greater<long long>> minheap;
        for(int i = 0 ; i < n ; i++){
            minheap.push(arr[i]);
        }
        
        long long cost = 0;
        
        while(minheap.size() >= 2){
            long long l1 = minheap.top();
            minheap.pop();
            
            long long l2 = minheap.top();
            minheap.pop();
            
            cost+=(l1+l2);
            
            minheap.push(l1+l2);
            
        }
        
        return cost;
        
        
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends