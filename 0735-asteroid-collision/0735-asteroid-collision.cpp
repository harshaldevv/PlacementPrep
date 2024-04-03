class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int>st;
        
        for(int i = 0 ; i <asteroids.size() ; i++){
            if(asteroids[i] > 0 || st.empty()){
                st.push(asteroids[i]);
            }
            else {
                if(!st.empty() && st.top() > 0 && asteroids[i] < 0){
                    cout << "going here" << endl;
                    while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])){
                        cout << "stack top = " << st.top() << endl;
                        cout << "asteroids[i] = " << asteroids[i] << endl;
                        st.pop();
                    }
                    if(!st.empty() && st.top() > 0 && asteroids[i] < 0 && st.top() == abs(asteroids[i])){
                        st.pop();
                        continue;
                    }
                }
                else if ((!st.empty() && st.top() < 0 && asteroids[i] > 0)){
                    cout << "going here 2 " << endl;
                    while(!st.empty() && st.top() < 0 &&abs(st.top()) <= abs(asteroids[i])){
                        st.pop();
                    }
                    
                    if(!st.empty() && st.top() < 0 && asteroids[i] > 0 && st.top() == abs(asteroids[i])){
                        st.pop();
                        continue;
                    }
                }
                
                if(st.empty() || st.top() < 0){
                    st.push(asteroids[i]);
                }
            }
            
        }
        
        
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};