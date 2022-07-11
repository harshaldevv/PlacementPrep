// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    // Compares two intervals according to starting times.
    static bool cmp( vector<int> &a, vector<int> &b ){
        return a[1] < b[1];
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<vector<int>> meetings;
        
        for(int i = 0 ; i < n ; i++){
            meetings.push_back({start[i], end[i]});
        }
        
        sort(meetings.begin(), meetings.end(), cmp);
        
        
        int l = meetings[0][1];
        // "l" represents the prev meeting end time
        int ans = 1;
        
        for(int i = 1 ; i< n ; i++){
            int r = meetings[i][0];
            int m = meetings[i][1];
            // r and m repesent the current meetings start and end time
            
            if( l < r){
                ans ++;
                l = m;
            }
        }
        
        return ans;
    }
    
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends