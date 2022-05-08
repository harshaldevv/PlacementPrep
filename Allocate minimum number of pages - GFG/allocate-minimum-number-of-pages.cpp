// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    
    bool isValid(int arr[], int n, int k , int maxPages){
        // k = students allowed as per question
        int students = 1;
        int sum = 0;
        
        for(int i = 0 ; i < n ; i++){
            sum += arr[i];
            if(sum > maxPages){
                students++;
                sum = arr[i];
            }
            if(students > k){
                return false;
            }
        }
        
        return true;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        // m = students
        if(M> N ){
            return -1;
        }
        
        int start = *max_element (A+ 0, A+ N);
        int end = accumulate(A+0, A+ N, 0);
        int res = -1;
        //cout << "start = " << start << " , end = " << end << endl;
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(isValid(A, N, M, mid)== true ){
                res = mid;
                end = mid -1;
            }
            
            else{
                start = mid +1;
            }
        }
        
        return  res;
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