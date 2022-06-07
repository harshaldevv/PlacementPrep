class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> s;
        unordered_set<string> vis;
        for(auto x : deadends){
            s.insert(x);
        }
        
        string start = "0000";
        
        if(s.find(start) != s.end()){
            return -1;
        }
        
        queue<string> q;
        q.push(start);
        
        int count = 0;
        
        while(!q.empty()){
        
            int sz = q.size();
            count++;
            
            while(sz--){
                
                auto front = q.front();
                q.pop();
                
                if(front == target){
                    return count-1 ;
                }
                
                
                
                for(int i = 0 ; i < 4 ; i++){
                    string temp = front;
                    
                    temp[i] = (front[i] - '0' + 1 )%10  + '0';
                    
                    if(!vis.count(temp) && !s.count(temp)){
                        vis.insert(temp);
                        q.push(temp);
                    }
                    
                    temp[i] = (front[i] - '0' - 1 + 10 )%10  + '0';
                    
                    if(!vis.count(temp) && !s.count(temp)){
                        vis.insert(temp);
                        q.push(temp);
                    }
                    
                }
            }
        }
        return -1;
        
    }
};