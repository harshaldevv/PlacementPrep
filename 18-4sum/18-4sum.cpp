class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        //overflow encounter kar raha tha isliye long long kahi kahi use krna pada
        // warna normally sab int me chal rha tha sab
        // see my first submission of this ques to realise what im saying
        for(int i = 0 ; i < n ; i++){
            for(int j = i +1 ; j < n ; j++){
                
                int l = j + 1;
                int r = n - 1;
                
                while(l < r){
                    long long a = (long long)nums[i];
                    long long b = (long long)nums[j];
                    long long c = (long long)nums[l];
                    long long d = (long long)nums[r];
                    
                    long long sum = a+b+c+d;
                    
                    if(sum == (long long)target){
                        // store
                        // ans.push_back({a,b,c,d});
                        ans.push_back({ nums[i], nums[j], nums[l], nums[r] });
                        
                        
                        while( l < r && nums[l] == nums[l+1]){
                            l++;
                        }
                        while(l < r && nums[r] == nums[r-1]){
                            r--;
                        }
                        
                        l++;
                        r--;
                    }
                    else if (sum < (long long)target){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
                
                //roll duplicates of number 2
                while( j + 1 < n && nums[j] == nums[j+1]){
                    j++;
                }
            }
            
            // roll duplicates of number 1
            while(i +1 < n && nums[i] == nums[i+1]){
                i++;
            }
        }
        
        return ans;
        
    }
};