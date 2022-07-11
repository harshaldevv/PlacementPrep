class Solution {
public:
//     void solve(vector<int> &nums, int i, vector<int> &holder, vector<vector<int>> &ans, set<vector<int>> &S){
//         if(i== nums.size()){
//             if(S.find(holder) == S.end()){
//                 S.insert(holder);
//                 ans.push_back(holder);
//             }
            
//             return;
//         }
        
//         //include
//         holder.push_back(nums[i]);
//         solve(nums, i+1, holder, ans, S);
        
//         //exlcude
//         holder.pop_back();
//         solve(nums, i+1, holder, ans, S);
        
//         return ;
//     }
    
    
    void solve2(vector<int> &nums, int i, vector<int> &holder, vector<vector<int>> &ans, bool pre){
        
        // pre holds if ive taken the ith value, so wrt i+1, it means if i took the prev value or not
        
        if(i== nums.size()){
            ans.push_back(holder);
            return ;
        }
        
        int e = nums[i];
        
        //include
        holder.push_back(e);
        solve2(nums, i+1, holder, ans, true);
        
        //agar ek baari le lia toh phir ab aage nahi lena duplicate number ko
        holder.pop_back(); // isliye pehle yahan holder se pop kardo
        
        if(i >0 && nums[i] == nums[i-1] && pre){
            return ;
        }
        
        //exclude
        
        solve2(nums, i+1, holder, ans, false);
        
        return;
        
        
//         //key thing here
//         // if im ignoring x, then i have to ignore all the occurences all of x that come 
//         // aka i also wont take those occurencs of x
//         // ignoring --> pre = false
        
//         //exclude
//         solve2(nums, i+1, holder, ans, false);
        
//         if(i>0 && nums[i] == nums[i-1] && !pre){
//             return;
//         }
        
//         //include
//         holder.push_back(nums[i]);
//         solve2(nums, i+1, holder, ans, true);
        
//         holder.pop_back();
        
//         return ;

        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        vector<int> holder;
        set<vector<int>> S;
        
        // solve(nums, 0, holder, ans, S); // this uses a set  -> this works but set uses extra space and time
        
        solve2(nums, 0, holder, ans , false); // this doesnt use a SET

        
        return ans;
        
    }
};