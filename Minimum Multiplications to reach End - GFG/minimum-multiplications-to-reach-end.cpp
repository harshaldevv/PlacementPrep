//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<vector<int>> q;
        int MOD = 100000;
        q.push({start,0}); // currnumber, steps
        vector<int> vis(100000, false); // visited array of size 10^5, bcz total
        // numbers can 
        while(!q.empty()){
            auto sz = q.size();
            while(sz--){
                auto front = q.front();
                q.pop();
                
                int currNumb = front[0];
                int currSteps = front[1];
                
                if(currNumb%MOD == end){
                    return currSteps;
                }
                
                for(int i = 0 ; i < arr.size() ; i++){
                    int temp = (currNumb * arr[i])%MOD;
                    if(!vis[temp]){
                        vis[temp] = true;
                        q.push({temp, currSteps +1});    
                    }
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends