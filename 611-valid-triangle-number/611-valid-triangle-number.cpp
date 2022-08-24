class Solution {
public:
    int doBinarySearch(int l, int r, int target, vector<int> &nums){
        int start = l;
        while(l<=r){
            
            int mid = l + (r-l)/2;
            
            if(nums[mid] < target){
                l = mid +1;
            }
            else{
                r = mid -1;
            }
            
        }
        
        return l - start;
    }
    
    int triangleNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        int cnt = 0;
        
//         for(int i = 0 ; i < n ; i++){
//             for(int j = i +1 ; j < n ; j++){
//                 for(int k = j +1  ; k < n ; k++){
                    
//                     int a = nums[i];
//                     int b = nums[j];
//                     int c = nums[k];
                    
//                     if(a+b > c && b +c > a && a+c > b){
//                         cnt++;
//                     }
//                 }
//             }
//         }
        // Brute --> O(n^3) , SC  - O(1)
        
        
        // Optimized --> O(n^2 * logn) , SC  - O(1)
        
//         sort(nums.begin(), nums.end());
        
//         for(int i = 0; i < n ; i++){
//             for(int j = i  +1 ; j < n ; j++){
//                 int a = nums[i];
//                 int b = nums[j];
                
//                 // binary search to find numbers less than a+b
//                 // if found incremenet cnt
//                 int temp = doBinarySearch(j+1, n-1, a+b , nums);
//                 cnt += temp;
//                 // cout << "temp = " << temp <<endl;
//             }
//         }
        
//         return cnt;
        
        
        
        // Best --> O(n^2)
        
        sort(nums.begin(), nums.end());
        for(int k = 2 ; k < n ; k++){
            
            int i = 0;
            int j = k-1;
            
            while(i<j){
                if(nums[i] + nums[j] > nums[k]){
                    cnt += (j-i);
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        
        return cnt;
        
    }
};