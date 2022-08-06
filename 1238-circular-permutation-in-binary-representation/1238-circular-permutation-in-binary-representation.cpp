class Solution {
public:
    void reverseKaro(vector<int> &nums, int l,int r){
        while(l<r){
            swap(nums[l++], nums[r--]);
        }
    }
    vector<int> circularPermutation(int n, int start) {
        
        int p = pow(2,n);
        
        vector<int> ans;
        
        //gray code
        for(int i = 0 ; i < p ; i++){
            // cout << (i^(i/2)) << endl;
            ans.push_back(i^(i/2));
        }

        
        
        // find the point where we our getting "start" in our array
        int i = 0;
        for( ; i < ans.size() ; i++){
            if(ans[i] == start){
                break;
            }
        }
        
        
        // now  rotate the array such that our "start" is at first
        // LC -> Rotate Array
        
        reverse(ans.begin(), ans.begin() + i );
    
        reverse(ans.begin() + i  , ans.end());
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
        
        
    }
};