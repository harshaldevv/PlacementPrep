class Solution {
public:
    void helper(int numb, vector<int> &holder, vector<vector<int>> &ans, int n, int k){
        if(k == 0){
            // this condn helps me to get my answer 
            ans.push_back(holder);
            return ;
        }
        
        if(numb > n){
            // stopping condition for further recursions
            return ;
        }
        
        //exclude (exclude the current number, therefore no decrease in the size of holder ie "k")
        helper(numb +1, holder, ans, n, k);
        
        
        //include (include the current number, therefore decrease the size of holder by 1, ie "k = k-1")
        holder.push_back(numb);
        helper(numb +1, holder, ans, n, k-1);
        
        holder.pop_back();
        
        
        return;
        
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans;
        vector<int> holder;
        helper(1, holder, ans, n, k);
        return ans;
        
        
    }
};