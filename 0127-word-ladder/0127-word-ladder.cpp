class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> set;
        
        for(auto &x : wordList){
            set.insert(x);
        }
        
        if(set.find(endWord) == set.end()){
            // nahi mila wordlist me
            return 0;
        }
       
        int ans = 0;
        
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()){
            int sz = q.size();
            ans++;
            
            while(sz--){
                auto front= q.front();
                q.pop();
                
                if(front == endWord){
                    return ans;
                }
                
                set.erase(front);
                
                for(int i = 0 ; i < front.size() ; i++){
                    string temp = front;
                    for( char c = 'a' ; c <= 'z' ; c++){
                        temp[i] = c;
                        if(set.find(temp) != set.end() ){
                            q.push(temp);  
                        }
                    }
                }
            }
        }
        
        return 0;

    }
};