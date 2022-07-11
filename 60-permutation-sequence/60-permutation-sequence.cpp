class Solution {
public:
    
    void nextPermutations (vector<int> &nums){
        int n = nums.size();
        // we want left small , right big
        
        int i = n-2;
        
        while( i >= 0 && nums[i] >= nums[i+1]){
            i--;
        }
        
        if( i == -1){
            // nums is reverse sorted
            reverse(nums.begin(), nums.end());
            return ;
        }
        
        //find just bigger number than nums[i];
        
        int next = n-1;
        for( ; next > i ; next--){
            if(nums[next] > nums[i]){
                break;
            }
        }
        
        // swap nums[i] and nums[next]
        swap(nums[i], nums[next]);
        
        // reverse from i +1 to end
        reverse(nums.begin() + i +1 , nums.end());
        
        return ;
    }
    string getPermutation(int n, int k) {
        
        //doing on 11th july using next permutations cuz thats the first approach that struck me
        vector<int> nums;
        for(int i = 1 ; i <= n ; i++){
            nums.push_back(i);
        }
        
        for(int i = 0; i < k-1 ; i++){
            nextPermutations(nums);
        }
        
        string ans = "";
        for(auto &x : nums){
            ans += to_string(x) ;
        }
        
        return ans;
        
        
//         vector<int> numbers;
//         for(int i = 1 ; i <= n ; i++){
//             numbers.push_back(i);
//         }
        
//         int f = 1;
//         vector<int> fact;
//         fact.push_back(1);
//         for(int i = 1 ; i <= n ; i++){
//             f*=i;
//             fact.push_back(f);
//         }
         
        
//         k--;
        
//         string ans = "";
        
//         while(n>0){
            
//             int factorial = fact[n-1];
            
//             int index = k/factorial;
//             // cout << "index = " << index << endl;
//             ans+= to_string(numbers[index]);
            
//             numbers.erase(numbers.begin() + index);
//             n--;
//             k=k%factorial;

//         }
        
//         return ans;

    }
};