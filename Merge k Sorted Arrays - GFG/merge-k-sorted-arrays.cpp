// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++

#define ppi pair<int, pair<int, int>> 
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        // min heap
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        
        // ppi
        // pair<int, pair<int, int>> == {elem, {ith array, jth index in the ith array}
        for(int i = 0 ; i< arr.size() ; i++){
            if(arr[i].size() > 0){
                pq.push({arr[i][0], {i, 0}});
            }
        }
        vector<int> ans;
        
        while(!pq.empty()){
            
            ppi front = pq.top();
            pq.pop();
            
            int elem = front.first;
            
            ans.push_back(elem);
            
            int i = front.second.first;
            int j = front.second.second;
            
            if(j+1 < arr[i].size() ){
                pq.push( {arr[i][j+1], {i, j+1} } );
            }
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends