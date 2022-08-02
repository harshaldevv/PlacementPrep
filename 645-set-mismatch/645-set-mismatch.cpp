class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s;
        
        int dupli = -1;
        for(auto x : nums){
            if(s.find(x) != s.end()){
                dupli = x;
                break;
            }
            s.insert(x);
        }
        
        int Actualsum = 0;
        int TotalSum = 0;
        int n = nums.size();
        
        for(int i =1 ; i <= n ; i++){
            Actualsum += i;
            TotalSum += nums[i-1];
        }
        cout <<"ActualSum = " << Actualsum << endl;
        cout <<"TotalSum = " << TotalSum << endl ;
        int diff = Actualsum - TotalSum;
        
        vector<int> ans(2, -1);
        ans[0] = dupli;
        ans[1] = dupli + diff;
        
        return ans;
    }
};