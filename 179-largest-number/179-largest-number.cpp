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
        
        
        
        
        // In this below while loop, we are trying to remove the trailing zeroes
       // as soon as we find the first non zero character, we return the substring 
        // of our answer string from that index to the end
       // Ques ? Why did we iterate till "n-1" and why not "n" ? 
        //--> because if our answer string = "0000", we want our answer = "0"
       // ie we need one "0" right, therefore we go till the second last character 
        // of the answer string and not the whole length of the answer string

        int i = 0;
        while(i< ans.size() -1){
            if(ans[i] != '0'){
                break;
            }
            i++;
        }
        
        return ans.substr(i);
        
        
        // or we could have counted the number of zeroes in our array, if it is equal
        // to arr.size(), it means our whole array is filled with zeroes,
        // therefore just return "0"; xD
        
    }
};
