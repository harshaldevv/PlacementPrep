class Solution {
public:
    
    static bool cmp(int &a, int &b){
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
    
    string largestNumber(vector<int>& nums) {
        // interviewbit question
        
        sort(nums.begin(), nums.end(), cmp); 
        // custom comparator for sorting
        
        string ans = "";
        
        for(auto &x : nums){
            ans += to_string(x);
        }
        
        
        // or we could have counted the number of zeroes in our array, if it is equal
        // to arr.size(), it means our whole array is filled with zeroes,
        // therefore just return "0";
        
        
        int i = 0;
        while(i< ans.size() -1){
            if(ans[i] != '0'){
                break;
            }
            i++;
        }
        
        return ans.substr(i);
        
    }
};