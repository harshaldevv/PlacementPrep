class StockSpanner {
public:
    stack<pair<int, int>> st; // price, index
    int i;
    StockSpanner() {
        
        i = 0;
    }
    
    int next(int price) {
        // NGL -- > do (my index - NGL index)  --> my index minus NGL index
        // -> my index = i , and NGL index jo bhi stack se ayega
        
        int res = 0;
        
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        
        if(st.empty()){
            // if st is empty, therefore NGL index = -1
            // therefore myindex - NGL index = i - (-1)
            
            res =  i - (-1); 
        }
        else{
            res = i - st.top().second +1; 
            // +1 because final - initial + 1, to get the length of the span
        }
        
        
        i++;
        st.push({price, i});
        
        return res;
        
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */