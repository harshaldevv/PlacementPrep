class Solution {
    
    vector<int> getNSR(vector<int> &arr){
        vector<int> ans;
        stack<pair<int, int>> st; // price, index
        
        for(int i = arr.size() -1 ; i>= 0 ;i--){
            while(!st.empty() && st.top().first > arr[i]){
                st.pop();
            }
            
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top().second);
            }
            
            st.push({arr[i], i});
        }
            
        reverse(ans.begin(), ans.end());

        // for(int i = 0 ; i < ans.size() ; i++){
        //     ans[i] = 
        // }
        
        return ans;
    }
public:
    vector<int> finalPrices(vector<int>& prices) {
        // find nsrIndex
        
        vector<int> nsr = getNSR(prices);
        
        for(int i = 0 ; i < prices.size() ; i++){
            if(nsr[i] == -1){
                continue;
            }
            else{
                prices[i] = prices[i] - prices[nsr[i]];
            }
        }
        
        return prices;
        
    }
};