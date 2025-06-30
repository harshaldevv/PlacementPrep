class Solution {
public:
    int maximumCount(vector<int>& nums) {

        // now using "SORTED ARRAY" -> we get the hint of binary search
        int l = 0;
        int r = nums.size() -1;

        // find the last index of -ve number
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] >= 0){
                // +ve hai, go left
                r = mid -1;
            }
            else{
                l = mid +1;
            }
        }

        // now lth index is the last -ve number
        int neg = l - 0 ; // either [0, ....... l ] -> length

        // now for +ve numbers;
        // find the first index of +ve number
        int start = 0;
        int end = nums.size() -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] <=0 ){
                start = mid +1;
            }
            else{
                end = mid -1;
            }
        }
        int n = nums.size() ;
        cout << "n = " << n << endl;
        int pos = n - (end+1);
        cout << "neg = " << neg << endl;
        cout << "l = " << l << endl;
        cout << "r = " << r << endl;
        cout << endl;

        cout << "pos = " << pos << endl;
        cout << "start = " << start << endl;
        cout << "end = " << end << endl;
        return max(neg, pos);














        // // brute force easy
        // int pos = 0;
        // int neg = 0;

        // for(auto &x : nums){
        //     if(x < 0 ){
        //         neg++;
        //     }
        //     else if(x > 0){
        //         pos++;
        //     }
        // }

        // return max(neg, pos);
        
    }
};