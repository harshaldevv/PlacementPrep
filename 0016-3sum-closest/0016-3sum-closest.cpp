class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = INT_MAX;
        int closestSum = 0;
        for(int i = 0 ; i < n ; i++){
            int A = nums[i];

            int l = i +1;
            int r = n-1;
            while(l < r){
                int B = nums[l];
                int C = nums[r];

                if(abs(A+B+C - target) < diff){
                    diff = abs(A+B+C - target);
                    closestSum = A+B+C;
                }

                if(A+B+C  == target){
                    return A+B+C;
                }
                else if(A+B+C > target){
                    r--;
                }
                else{
                    l++;
                }

            }
        }
        cout << "diff = " << diff << endl;
        return closestSum;
        
    }
};