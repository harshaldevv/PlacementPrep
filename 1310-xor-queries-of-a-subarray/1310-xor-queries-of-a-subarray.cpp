class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> preXor(n, -1);
        
        preXor[0] = arr[0];
        
        for(int i = 1 ; i < n ; i++){
            preXor[i] = preXor[i-1] ^arr[i];
        }
        
        for(auto &x : preXor){
            cout << x << " ";
        }
        
        cout <<"here3";
        
        vector<int> ans;
        
        for(int i = 0 ; i < queries.size() ; i++){
            int start = queries[i][0];
            int end = queries[i][1];
            
            if(start == 0){
                ans.push_back(preXor[end]);
            }
            else{
                //start != 0;
                cout <<"here"<<endl;
                ans.push_back(preXor[start-1]^preXor[end]);
            }
        }
        
        return ans;
        
        
    }
};