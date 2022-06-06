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
        
        q.push({start, arr[start]});
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            int index = front.first;
            int val = front.second;
            if(val == 0){
                return true;
            }
            if(val<0){
                continue;
            }
            
            int temp1 = index +  val;
            int temp2 = index - val;
            
            if(isvalid(temp1, n)){
                q.push({temp1, arr[temp1]});
            }
            if(isvalid(temp2, n)){
                q.push({temp2, arr[temp2]});
            }
            
            arr[index] = -val; // negating the value which we have --> 
            // since array has non negative numbers, therefore if we negate a number
            // and we aage kabhi encounter a negative number, then we know it is already visited;
            // therefore we "continue" the code;
            
        }
        
        return false;
        
        
        
        
//         SC - O(N) --> it can be optimised , see above
//         TC - O(N)
        
//         int n = arr.size();
        
//         queue<pair<int, int>> q;
        
//         vector<bool> vis(n, false); 
//         // need this , else as you can see in test case example 3,
//         // {index, val} --> {2,2} && {4,2} oscillate karte rahenge
        
//         q.push({start, arr[start]});
//         vis[start] = true;
        
        
//         while(!q.empty()){
//             auto front = q.front();
//             q.pop();
//             int index = front.first;
//             int val = front.second;
            
//             if(val == 0){
//                 return true;
//             }
            
            
//             int temp1 = index + val;
//             int temp2 = index - val;
            
//             if(isvalid(temp1, n)){
//                 if(!vis[temp1]){
//                     q.push({temp1, arr[temp1]});
//                     vis[temp1] = true;
//                 }
                
//             }
//             if(isvalid(temp2, n)){
//                 if(!vis[temp2]){
//                     q.push({temp2, arr[temp2]});
//                     vis[temp2] = true;
//                 }
//             }
//         }
        
//         return false;
        
    }
};