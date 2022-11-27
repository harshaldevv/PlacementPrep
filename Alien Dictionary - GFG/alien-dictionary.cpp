//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void toposort(int &curr, vector<vector<int>> &adjList, vector<bool> &vis, stack<int> &st ){
        if(vis[curr]){
            return ;
        }
        vis[curr] = true;
        
        for(auto &next : adjList[curr]){
            if(!vis[next]){
                toposort(next, adjList, vis, st);
            }
        }
        st.push(curr);
        return;
    }
    
    bool cycledetect(int &curr, vector<bool> &vis,vector<bool> &dfsvis, vector<vector<int>> &adjList ){
        
        // cycledetect(i, vis2, dfsvis, adjList)
        
        vis[curr] = true;
        dfsvis[curr] = true;
        
        for(auto &next : adjList[curr]){
            if(!vis[next]){
                if(cycledetect(next, vis, dfsvis, adjList)){
                    return true;
                }
            }
            else if(dfsvis[next]){
                //already visited
                return true;
            }
        }
        
        dfsvis[curr] = false;
        return false;
    }
    
    string findOrder(string dict[], int N, int k) {
        //code here
        // toposort
        
        vector<vector<int>> adjList(k);
        
        for(int i = 0 ; i < N-1 ;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int L = min(s1.size(), s2.size());
            
            for(int j = 0 ; j < L; j++){
                if(s1[j] != s2[j]){
                    adjList[s1[j] -'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        
        // a, ab
        
        
        //got our adjList
        
        // do toposort(dfs wali)
        
        // detect cycle pehle --> if cycle exists return empty string
        // //dfs vis wala
        
        vector<bool> vis2(k, false);
        vector<bool> dfsvis(k, false);;
        for(int i = 0 ; i < k ; i++){
            if(!vis2[i]){
                if(cycledetect(i, vis2, dfsvis, adjList)){
                    return "";
                }
            }
        }
        
        vector<bool> vis(k, false);
        stack<int> st;
        for(int i = 0 ; i < k ;i++){
            if(!vis[i]){
                toposort(i, adjList, vis, st);
            }
        }
        
        string ans = "";
        
        if(st.size() < k){
            return ans;
        }
        
        while(!st.empty()){
            ans.push_back(st.top() +'a');
            st.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends