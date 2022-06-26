class Solution {
public:
    void solve(int i, vector<int> nums, vector<vector<int>> &ans){
        //nums is passed by value
        if(i== nums.size()){
            ans.push_back(nums);
            return ;
        }
       
        
        for(int j = i ; j < nums.size() ; j++){
            
            if(j != i && nums[i] == nums[j] ){
                continue;
            }
            
            swap(nums[i], nums[j]);
            solve(i+1, nums, ans);
       
            
            //exclude
            //swap(nums[i], nums[j]);
        }
        
        return ;
    }
    
    bool nextPermutations(vector<int> &nums){
        
        int n = nums.size();
        
        int i= n-2;
        
        // 1 2 4 3 2 1
        // left small, right big
        while(i>=0 && nums[i] >= nums[i+1]){
            i--;
        }
        
        if(i==-1){
            return false;
            // if nums = [3,2,1]
            // toh iska next permutations nahi exist krta
            //isliye false return krdo
        }
        
        //find next bigger than nums[i]
        int next = n-1;
        for(  ; next > i ; next--){
            if(nums[next] > nums[i]){
                break;
            }
        }
        
        swap(nums[i], nums[next]);
        
        reverse(nums.begin() +i +1, nums.end());
        
        return true;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
//         sort(nums.begin(), nums.end());
        
//         vector<vector<int>> ans;
//         solve(0, nums, ans);
        
//         return ans;
        
    // Above --> Backtracking
        
    // Below --> Next Permutation
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.push_back(nums);
        
        while(nextPermutations(nums)){
            ans.push_back(nums);
        }
        
        return ans;
    }
};