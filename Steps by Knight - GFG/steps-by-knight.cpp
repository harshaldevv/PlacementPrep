// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    bool isValid(int i, int j, int n){
        if(i >=1 && j >= 1 && j<= n && i <= n){
            return true;
        }
        return false;
    }
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    
	    vector<vector<bool>> vis(N +1, vector<bool>(N+1, false));
	    
	    int tx = TargetPos[0];
	    int ty = TargetPos[1];
	    
	    int x = KnightPos[0];
	    int y = KnightPos[1];
	    
	    if(tx == x && ty == y){
	        return 0;
	    }
	    
	    int n = N;
	    
	    queue<pair<int, int>> q;
	    q.push({x,y});
	    vis[x][y] = true;
	    
	    int ans = 0;
	    
	    int dir[8][2] = { {-2, -1}, {-1, -2}, {+1, -2}, {+2, -1}, {+2, +1}, {+1, +2}, {-1, +2}, {-2, +1} };
	    
	    
	    while(!q.empty()){
	        int sz = q.size();
	        ans++;
	        while(sz--){
	            pair<int, int> front = q.front();
	            q.pop();
	            
	            int currX = front.first;
	            int currY = front.second;
	            
	            if(currX == tx && currY == ty){
	                return ans-1;
	            }
	            
	            for(int i = 0 ; i < 8 ; i++){
	                int newX = currX + dir[i][0];
	                int newY = currY + dir[i][1];
	                
	                if(isValid(newX, newY,n) && !vis[newX][newY]){
	                    vis[newX][newY] = true;
	                    q.push({newX, newY});
	                }
	            }
	        }
	    }
	   // cout << "ans = " << ans;
	    return ans-1 ;
	    
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends