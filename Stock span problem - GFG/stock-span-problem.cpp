// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        // NGL basically
        vector<int> ans;
        stack<pair<int, int>> st;
        
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && st.top().first <= price[i]){
                st.pop();
            }
            
            if(st.empty()){
                ans.push_back(i-(-1));
            }
            else{
                ans.push_back(i - st.top().second);
            }
            
            pair<int, int> p(price[i], i);
            st.push(p);
        }
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    //   // Your code here
    //   vector<int> v;
    //   stack<pair<int, int>> st;  // first -> price ; second - > index
    //   vector<int> ans(n);
       
    //   for(int i = 0 ; i < n ; i++){
           
    //       while(!st.empty() && st.top().first <= price[i]){
    //           st.pop();
    //       }
           
    //       if(st.empty()){
    //           v.push_back(-1);
    //       }
    //       else{
    //           v.push_back(st.top().second );
    //       }
    //       pair<int, int> p(price[i], i);
    //       st.push(p);
           
    //       ans[i] = i - v[i];
    //   }
       
    //   return ans;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends