class Solution {
public:
    void solve(vector<int> &nums, int i, vector<vector<int>> &ans){
        
        if(i == nums.size()){
            ans.push_back(nums);
            return ;
        }
        
        for(int j = i; j < nums.size() ; j++){
            
            swap(nums[i], nums[j]);
            
            solve(nums, i+1, ans);
            
            swap(nums[i], nums[j]); // back track step
        }
        
        return ;
    }
    int fact(int n){
        if(n <=1){
            return 1;
        }
        return n*fact(n-1);
    }
    
    void nextPermutation(vector<int> &nums){
        int n = nums.size();
        
        // left small, right big
        int i = n-2;
        
        while(i>= 0 && nums[i] >= nums[i+1]){
            i--;
        }
        
        if( i == -1){
            // cuz we got reverse sorted array now, and hume ab stop karna hai
            // cuz ye last permutation hai 
            return ;
        }
        
        // we got our small --> nums[i]
        
        //find the next bigger number than nums[i];
        
        int next = n-1;
        
        for ( ; next > i ; next--){
            if(nums[next] > nums[i]){
                break;
            }
        }
        
        // swap nums[i], nums[next]
        swap (nums[i], nums[next]);
        
        // reverse from i+1;
        reverse(nums.begin() + i +1 , nums.end());
        
        return ;
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        // doing on 12 July using next permutations
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        ans.push_back(nums);
        
        for(int i = 1 ; i < fact(n) ; i++){
            nextPermutation(nums);
            ans.push_back(nums);
        }
        
        return ans;
        
        
//         vector<vector<int>> ans;
        
//         solve(nums, 0, ans);
        
//         return ans;
        
//         // https://leetcode.com/problems/permutations/discuss/1961596/C%2B%2B-oror-Easy-to-Understand-with-Diagram-oror-0-ms-oror-Backtracking
        
//         // diagram helped me formulating the soln
        
    }
};