class Solution {
public:
    int reversePairs(vector<int>& nums) {
        
        //redo --> 9 July 2021
        
        return reversePairsHelper(nums, 0, nums.size() -1); // T[ l , ...., r]
        
    }
    
    int reversePairsHelper(vector<int> &nums, int l, int r){
        
        if(r <= l){
            return 0 ; // even one element isnt allowed, as a single element cant form a pair
        }
        
        long long ans = 0;
        
        int m = l + (r-l)/2;
        
        ans += reversePairsHelper(nums, l, m);
        ans += reversePairsHelper(nums, m+1, r);
        ans += merge(nums, l,m,r);
        
        return ans;
    }
    
    int merge(vector<int> &nums, int l, int m, int r){
        
        // count the pairs
        int cnt = 0;
        
        int j = m +1;
        
        for(int i = l ; i <= m ; i++){
            // cout << "nums[i] = " << nums[i] << " nums[j] = " << nums[j] << endl;
            
            // while(j<= r && nums[i] > 2*nums[j]){ // this works but we need to take care of overflow
            while(j <= r && (long long)(nums[i]) > 2*(long long)(nums[j])){
                j++;
            }
            cnt +=( j- (m +1));
        }
        
        //now sort the array
        vector<int> temp;
        
        int left = l;
        int right = m +1;
        
        while(left <= m && right <= r){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
                
            }
        }
        
        while(left <= m){
            temp.push_back(nums[left]);
            left++;
        }
        
        while(right <= r){
            temp.push_back(nums[right]);
            right++;
        }
        
        int sizeofTemp = temp.size();
        
        for(int i = l; i <= r ; i++){
            nums[i] = temp[i-l];
        }
        
        return cnt;
        
        
    }
};