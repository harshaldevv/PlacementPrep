// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool isPossible(bool graph[101][101], int currvertex, int colorToFill, vector<int> &color,  int m, int n){
    
    for(int i = 0 ; i < n ; i++){
        if(graph[currvertex][i] == 1 ){
            // check if vertices sharing an edge with currvetex,
            // if they share an edge,
            // then i will check if the color of those vertices that share an edge
            // with my currentvertex, is same or not
            // if it is same, then i wil return false, stating that it
            // is not possible to color our current vertex with this color
            // because a vertex sharing an edge with this currentvertex of mine,
            // has the same color
            if(color[i] == colorToFill){
                return false;
            }
        }
    }
    
    
    return true;
}
bool helper(bool graph[101][101], int currvertex, vector<int> &color, int m, int n){
    if(currvertex == n){
        return true; // we've succesfully colored all our vertices
    }
    
    for(int i = 0 ; i < m ; i++){
        // i  means my i-th color --> and color(vector) stores which vertex has what color
        if(isPossible(graph, currvertex, i, color, m, n)){
            
            color[currvertex] = i;
            
            if(helper(graph, currvertex+1, color, m, n)){
                return true;
            }
            else{
                color[currvertex] = -1;
            }
        }
    }
    
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    // n = vertices
    // m = colors
    
    vector<int> color(n, -1);
    
    // 0 --> current vertex
    return helper(graph, 0, color, m, n);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends