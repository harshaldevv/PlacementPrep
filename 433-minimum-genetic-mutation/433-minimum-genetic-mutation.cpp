class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> s;
        
        // s.insert(start);
        for(auto x : bank){
            s.insert(x);
        }
        
        if(s.find(end) == s.end()){
            cout << "here" << endl;
            return -1;
        }
        
        
        
        int n = start.size();
        
        int count = 0 ;
        
        queue<string> q;
        q.push(start);
        
        // vector<char> mut = {'A', 'C', 'G', 'T'};
        
        while(!q.empty()){
            int sz = q.size();
            count++;
            while(sz--){
                
                auto front = q.front();
                q.pop();
                
                if(front == end){
                    return count-1;
                }
                
                s.erase(front);
                
                for(int i = 0 ; i < n ; i++){ /// n = 8 --> str length
                    
                    string temp = front;
                    
                    temp[i] = 'A';
                    if(s.count(temp)){
                        // this mutation exists in our bank
                        q.push(temp);
                    }
                    
                    temp[i] = 'C';
                    if(s.count(temp)){
                        // this mutation exists in our bank
                        q.push(temp);
                    }
                    
                    temp[i] = 'G';
                    if(s.count(temp)){
                        // this mutation exists in our bank
                        q.push(temp);
                    }
                    
                    temp[i] = 'T';
                    if(s.count(temp)){
                        // this mutation exists in our bank
                        q.push(temp);
                    }
                    
                }
                
            }
        }
        
        return -1;
        
    }
};