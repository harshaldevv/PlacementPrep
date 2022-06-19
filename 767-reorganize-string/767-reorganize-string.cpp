class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char, int> mp;
        for(int i = 0 ; i< s.size() ; i++){
            mp[s[i]]++;
        }
        
        priority_queue<pair<int, char>> pq;
        
        for(auto &x : mp){
            pq.push({ x.second, x.first});
        }
        
        string ans = "";
        if(pq.top().first > ( s.size()+1 ) /2){
            return ans; // if this character has frequency more than half
            // the length of the string, it is impossible to arrange it
            // in any order
        }
        
        while(pq.size() > 1){
             
            // any two adjacent characters are not the same
            auto top1 = pq.top() ; pq.pop();
            auto top2 = pq.top() ; pq.pop();
            
            ans += top1.second;
            ans += top2.second;
            // ans.push_back
            
            top1.first--;
            top2.first--;
            
            if(top1.first > 0){
                pq.push({top1.first, top1.second});
            }
            
            if(top2.first > 0){
                pq.push({top2.first, top2.second});
            }
            
        }
        
        //now heap size == 1
        if(!pq.empty()){
            auto top = pq.top();
            if(top.first > 1){
                return "";
            }
            else{
                ans+= top.second;
            }
        }
        
        
        return ans;
        
        
        
        
        
        
    }
};