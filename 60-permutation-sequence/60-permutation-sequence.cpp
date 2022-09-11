class Solution {
public:
    
    void nextPerm(vector<int> &nums){
        // left small, right big
        int n = nums.size();
        
        int i =  n-2;
        
        for( ; i >= 0 ; i--){
            if(nums[i] < nums[i+1]){
                break;
            }
        }
        
        if(i==-1){
            //reverse sorted
            reverse(nums.begin(), nums.end());
            return ;
        }
        
        // next bigger number 
        int j = n-1;
        
        for( ; j > i ; j--){
            if(nums[j] > nums[i]){
                break;
            }
        }
        
        // swap
        swap(nums[i], nums[j]);
        
        reverse(nums.begin() + i +1 , nums.end());
        
        return ;
        
    }
    string getPermutation(int n, int k) {
        
        vector<int> nums;
        
        // string N = to_string(n);
        
        for(int i = 1 ; i <= n ; i++){
            nums.push_back(i);
        }
        
        // for(auto & x : nums){
        //     cout << x << " ";
        // }
        
        for(int i = 0 ; i < k -1; i++){
            nextPerm(nums);
        }
        
        string ans = "";
        
        for(auto & x : nums){
            ans += to_string(x);
        }
        
        return ans;
        
        
    }
};