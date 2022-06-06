class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        // NOT MINE
	//to hold forbidden positions
	unordered_set<int> st{forbidden.begin(),forbidden.end()};
	queue<pair<int,int>> Q;
	//pait {a,b} a---> position b----> last jump(forward===0 or backward==1)
	Q.push({0,0});
	//insert 0 in forbidden list
	st.insert(0);
	int steps=0;
	while(!Q.empty()){
		int s=Q.size();
		while(s--){
			int u=Q.front().first;
			int f=Q.front().second;
			Q.pop();
			if(u==x) return steps;
			//r---->forward jump,l----->backward jump
			int r=u+a,l=u-b;
			//backward jump only if previous jump is forward and position is not in forbidden list
			if(!f and l>=0 and !st.count(l)){
				st.insert(l);
				Q.push({l,1});
			}
			// As x,a,b take max values of 2000 each, max forward jump can be 6000
			if(r<=6000 and !st.count(r)){
				st.insert(r);
				Q.push({r,0});
			}
		}
		steps++;
	}
	return -1;
}
};