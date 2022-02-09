// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    vector<long long > NSR( long long arr[], int n){
        stack<pair<long, int>> st;
        vector<long long > v;
        
        int pseudoIndex = n;
        
        for(int i = n-1; i >=0 ; i--){
            if(st.size() == 0){
                v.push_back(pseudoIndex);
            }
            else if(st.size() > 0 && st.top().first < arr[i]){
                v.push_back(st.top().second);
            }
            else if (st.size() > 0 && st.top().first >= arr[i]){
                while(st.size() > 0 && st.top().first >= arr[i]){
                    st.pop();
                }
                if(st.size() == 0){
                    v.push_back(pseudoIndex);
                }
                else{
                    v.push_back(st.top().second);
                }
                
            }
            
            st.push({arr[i], i});
        }
        
        reverse(v.begin(), v.end());
        return v;
    }
    
    vector<long long > NSL( long long arr[], int n){
        stack<pair<long, int>> st;
        vector<long long > v;
        
        int pseudoIndex = -1;
        
        for(int i = 0 ; i < n ; i ++){
            if(st.size() == 0){
                v.push_back(pseudoIndex);
            }
            else if(st.size() > 0 && st.top().first < arr[i]){
                v.push_back(st.top().second);
            }
            else if (st.size() > 0 && st.top().first >= arr[i]){
                while(st.size() > 0 && st.top().first >= arr[i]){
                    st.pop();
                }
                if(st.size() == 0){
                    v.push_back(pseudoIndex);
                }
                else{
                    v.push_back(st.top().second);
                }
                
            }
            
            st.push({arr[i], i});
        }
        
        // reverse(v.begin(), v.end());
        return v;
    }
    
    
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        
        // find NSR
        vector<long long > right = NSR(arr,n);
         
        // find NSL
        vector<long long > left = NSL(arr,n);
        
        // find width[] & area[] and maxArea;
        long long maxArea = -1;
        vector<long long> width(n, -1);
        vector<long long> area(n, -1);
        
        for(int i = 0 ; i  < n ; i++){
            width[i] = right[i] - left[i] - 1;
            area[i] = width[i] *arr[i];
            maxArea = max(area[i], maxArea);
        }
        
        
        // return maxArea;
        
        return maxArea;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends