//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        unordered_map<int, int> mp;
        
        int l = 0;
        int r = 0;
        
        vector<int> ans;
        
        while(r< n){
            
            if(r-l +1 <= k){
                int x = A[r];
                mp[x]++;   
                
                if(r-l +1 == k){
                    ans.push_back(mp.size());
                }
                r++;
            }
            else{
                int y = A[l];
                mp[y]--;
                if(mp[y] == 0){
                    mp.erase(y);
                }
                
                if(r-l +1== k){
                    ans.push_back(mp.size());
                }
                
                l++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends