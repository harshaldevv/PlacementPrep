class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // Hint - How many majority elements could it possibly have
        // Ans - maximum 2 majority elements --> Therefore try doing it in constant space complexity
        
        int count1 = 0;
        int count2 = 0;
        
        int numb1 = INT_MIN;
        int numb2 = INT_MIN;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(numb1 == nums[i]){
                count1++;
            }
            else if(numb2 == nums[i]){
                count2++;
            }
            else if(count1 ==0){
                numb1 = nums[i];
                count1++;
            }
            else if (count2 == 0){
                numb2 = nums[i];
                count2++;
            }
            else{
                count1--, count2--;
            }
        }
        
        vector<int> ans;
        
        int c1=0;
        int c2 = 0;
        
        for(int  i = 0 ; i < n ; i++){
            if(nums[i] == numb1){
                c1++;
            }
            if(nums[i] == numb2){
                c2++;
            }
        }
        
        
        if(c1 > n/3){
            ans.push_back(numb1);
        }
        if(c2 > n/3){
            ans.push_back(numb2);
        }
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
//         unordered_map<int, int> mp;
//         unordered_map<int, int> mp2;
        
//         int n = nums.size();
        
//         vector<int> ans;
        
//         for(int i = 0 ; i < n; i++){
        
//             mp[nums[i]]++;
//         }
        
//         for( auto it : mp){
//             if(it.second > n/3){
//                 ans.push_back(it.first);
//             }
//         }
        
//         return ans;
        
    }
};