// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int> Kclosest(vector<int>arr, int n, int x, int k) 
    { 
        // Your code goes here 
        
        // K closest 
        // max heap
        priority_queue<pair<int,int>, vector<pair<int, int>> > maxheap;
        
        for(int i = 0 ; i < n ; i++){
            maxheap.push({abs(x - arr[i]), arr[i]});
            if(maxheap.size() > k){
                maxheap.pop();
            }
        }
        
        vector<int> ans;
        while(!maxheap.empty()){
            
            auto topPair = maxheap.top();
            maxheap.pop();
            
            int neigh = topPair.second;
            
            ans.push_back(neigh);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }  
};

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,k;
		cin>>n>>x>>k; 
		vector <int> array(n);
		for (int i = 0; i < n; ++i)
			cin>>array[i];
        
        Solution obj;
		vector <int> result = obj.Kclosest(array, n, x, k); 
		for (int i = 0; i < result.size(); ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}

	return 0; 
} 



  // } Driver Code Ends