class MinStack {
private:
    stack<int> s;
    stack<int> ss; // supporting stacks --> only stores the minimum elements in it

public:
    MinStack() {
        // minstack implementation with O(N) extra space
        ;
    }
    
    void push(int val) {
        s.push(val);
        
        if(ss.size() == 0 || val <= ss.top()){
            ss.push(val);
        }
        return;
        
    }
    
    void pop() {
        int temp = s.top();
        s.pop();
        if(temp == ss.top()){
            ss.pop();
        }
        
        
    }
    
    int top() {
        return s.top();
        
    }
    
    int getMin() {
        return ss.top();
        
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