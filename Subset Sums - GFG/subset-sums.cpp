// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void helper(vector<int> &arr, vector<int> &holder, int i, vector<vector<int>> &ans){
        if( i== arr.size()){
            ans.push_back(holder);
            return ;
        }
        
        // include
        holder.push_back(arr[i]);
        helper(arr, holder, i+1, ans);
        
        //exclude
        holder.pop_back();
        helper(arr, holder, i+1, ans);
        
        return;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
         
        vector<int> holder; // empty set
        vector<vector<int>> ans;
        int i = 0;
        
        helper(arr, holder, i, ans );
        // first i store all the subsets --> using helper() function
        
        // then i will sum all the individual subsets to get each subset's sum
        vector<int> result( ans.size(), -1);
        
        for(int i = 0 ; i < result.size() ; i++){
            result [i] = accumulate(ans[i].begin(), ans[i].end(), 0);
            
        }
        
        return result;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends