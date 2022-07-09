// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
        int k = 0 ; // find subarray with sum = k , here k = 0
        
        // vector<int> prefixsum(n, -1);
        // prefixsum[0] = arr[0];
        
        // for(int i = 1 ; i < n ; i++ ){
        //     prefixsum[i]  = prefixsum[i-1] + arr[i];
        // }
        
        
        int presum = 0;
        
        unordered_map<int, int> mp;
        
        int ans = 0;
        
        
        for(int i  = 0 ; i < n ; i++){
            
            presum += arr[i];
            if(presum==0){
                ans = i+1;
                continue;
            }
                
            if(mp.find(presum - k)!=mp.end()){
                ans = max(ans, i - mp[presum-k] );
            }
            else{
                mp[presum] = i;
            }
        }
        return ans ;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends