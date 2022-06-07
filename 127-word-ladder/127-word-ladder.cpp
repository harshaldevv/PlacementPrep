class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> s (wordList.begin(), wordList.end());
        unordered_set<string> vis;
        
        if(s.find(endWord) == s.end()){
            // nahi mila wordlist me
            return 0;
        }
        
        queue<string> q;
        q.push(beginWord);
        
        int count = 0;
    
        while(!q.empty()){
            int sz = q.size();
            count++;
            
            while(sz--){
                auto front = q.front();
                q.pop();
                if(front == endWord){
                    return count;
                }
                
                s.erase(front);
                
                for(int i = 0 ; i < front.size() ; i++){
                    string temp = front;
                    for(int k = 0 ; k < 26 ; k++){
                        temp[i] = 'a' + k;
                        if(s.find(temp) != s.end() && vis.find(temp) == vis.end()){
                            // temp is in our dict 
                            // and temp is not visited yet
                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};