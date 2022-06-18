#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void solve(){
    int n, k;
	cin >> n >> k;
	
	vector<int> v;
	for(int i = 0 ; i < n ; i++){
	    int x;
	    cin >> x;
	    v.push_back(x);
	}
	
	// min heap
	priority_queue<int, vector<int>, greater<int>> minheap;
	vector<int> ans;
	for(int i = 0 ; i < n ; i++){
	    minheap.push(v[i]);
	    if(minheap.size() > k){
	        cout << minheap.top() << " " ;
	        ans.push_back(v[i]);
	        minheap.pop();
	    }
	}
	
	while(minheap.size() > 0){
	    cout << minheap.top() << " " ;
	    ans.push_back(v[minheap.top()]);
	    minheap.pop();
	}
	cout << endl;
	return ;
	
	
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    solve();
	}
	return 0;
}