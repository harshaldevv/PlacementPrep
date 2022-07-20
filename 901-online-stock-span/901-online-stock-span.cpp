class StockSpanner {
public:
    stack<pair<int, int>> st; // price, index
    int i;
    StockSpanner() {
        
        i = 0;
    }
    
    int next(int price) {
        
        int res = 0;
        
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        
        if(st.empty()){
            res =  i+1; //   i -(-1);
        }
        else{
            res = i - st.top().second +1;
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