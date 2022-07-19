class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        
        vector<int> temp;
        temp.push_back(1);
        ans.push_back(temp);
        
        if(n == 1){
            return ans;
        }
        
        temp.push_back(1);
        ans.push_back(temp);
        
        if(n == 2){
            return ans;
        }
        // cout <<"here" << endl;
        
        for(int i = 3 ; i <= n ;i++){
            // cout << "i = " << i << endl;
            vector<int> holder(i, 1);
            // cout << "pika = " << ans.back().size() << endl;
            for(int j = 1 ; j < ans.back().size() ; j++){
                // cout << "j = " << j << endl;
                holder[j] = ans.back()[j] + ans.back()[j-1];
                // cout << "j = " << j << endl;
            }
            ans.push_back(holder);
        }
        
        return ans;
    }
};