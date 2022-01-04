class Solution {
public:
    
//     int localINV(vector<int>& nums){
//         int ans = 0;
//         for(int i = 0 ;  i < nums.size() -1 ; i++){
//             if(nums[i] > nums[i+1]){
//                 ans++;
//             }
//         }
        
//         return ans;
//     }
    
//     int countSplitInv(vector<int> &nums, int l, int mid, int r){
//         int n1 = mid - l +1;
//         int n2 = r - mid;
        
//         vector<int> a(n1, - 1) ;
//         vector<int> b(n2, - 1) ;
        
//         for(int i = 0 ;  i < n1 ; i++){
//             a[i] = nums[l + i];
//         }
        
//         for(int i = 0 ;  i < n2 ; i++){
//             b[i] = nums[mid + 1+ i];
//         }
        
        
//         int i = 0 ;
//         int j = 0;
//         int k = l;
        
//         int inv = 0;
        
//         cout << "here 1" << endl;
//         while ( i < n1 && j < n2){
//             if(a[i] < b[j]){
//                 nums[k++] = a[i++];
//             }
//             else{
//                 inv += (n1 - i);
//                 nums[k++] = b[j++];
                
//             }
//         }
        
//         cout << "here 2" << endl;
        
//         while(i < n1){
//             nums[k++] = a[i++];
//         }
        
//         cout << "here 3" << endl;
        
//         while(j < n2){
//             nums[k++] = b[j++];
//         }
        
//         cout << "here 4" << endl;
        
//         return inv;
        
        
//     }
    
//     int globalINV( vector<int> &nums, int l, int r){
//         if (  l >=r ){
//             return 0;
//         }
        
//         if( r>l){
//             int mid = l + ( r-l)/2;
            
//             int left = globalINV(nums, l, mid);
//             int right = globalINV(nums, mid+1, r);
//             int splitInv = countSplitInv(nums, l, mid, r);
            
//             return left + right + splitInv;
//         }
//         else{
//             return 0; // :)
//         }
        
//     }
    
    
    bool isIdealPermutation(vector<int>& nums) {
        
        int n = nums.size();
        
        for(int i = 0 ; i < n ; i++){
            if(abs(nums[i] - i) > 1){
                return false;
            }
        }
        
        return true;
        
//         int local = localINV(nums); // TC - O(N);
//         int n = nums.size();
        
//         int global = globalINV(nums, 0 , n -1);
        
//         if(local == global){
//             return true;
//         }
//         else{
//             return false;
//         }
        
    }  
};