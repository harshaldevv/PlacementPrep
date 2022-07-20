class MinStack {
public:
    stack<long> st;
    long  minEle = -1;
    MinStack() {
        // min stack implementation with CONSTANT SPACE O(1)
        ;
    }
    
    void push(long val) {
        
        if(st.size() == 0){
            st.push(val);
            minEle = val;
        }
        else if(val < minEle){
            // push 2x - minele
            st.push(2*val - minEle);
            minEle = val;
            
        }
        else{
            st.push(val);
        }
        
        return ;
        
    }
    
    void pop() {
        // while popping,
        // if st.top() < minele -->  update the minEle --> 
        // as our st.top() being less than our minele is a "flag" for us
        // that we gotta now go back to the minelement that was just before our current minelement
        
        if(st.top() < minEle){
            minEle = 2*minEle - st.top();
        }
        
        st.pop();
    }
    
    int top() {
        
        if(st.top() < minEle){
            return minEle;
        }
        else{
            return st.top();
        }
 
    }
    
    int getMin() {
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */