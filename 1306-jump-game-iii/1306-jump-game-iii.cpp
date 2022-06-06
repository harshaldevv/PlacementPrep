class Solution {
public:
    
    bool isvalid(int x, int n){
        if(x >= n || x < 0){
            return false;
        }
        return true;
    }
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        
        queue<pair<int, int>> q;
        vector<bool> vis(n, false);
        
        q.push({start, arr[start]});
        vis[start] = true;
        
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int index = front.first;
            int val = front.second;
            
            if(val == 0){
                return true;
            }
            
            
            int temp1 = index + val;
            int temp2 = index - val;
            
            if(isvalid(temp1, n)){
                if(!vis[temp1]){
                    q.push({temp1, arr[temp1]});
                    vis[temp1] = true;
                }
                
            }
            if(isvalid(temp2, n)){
                if(!vis[temp2]){
                    q.push({temp2, arr[temp2]});
                    vis[temp2] = true;
                }
            }
        }
        return false;
        
    }
};