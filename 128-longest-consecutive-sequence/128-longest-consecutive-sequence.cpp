class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // TC - O(N), SC - O(N)
        // put our numbers in the unordered_set
        int n = nums.size();
        
        unordered_set<int> SET;
        
        for(int i = 0 ; i <  n ; i++){
            int x = nums[i];
            SET.insert(x);
        }
        
        int length = 0;
        for(auto x : nums){
            if(SET.find(x-1) == SET.end()){
                // if x-1 isnt in the set, it means we are the beginning of the sequence
                int y = x+1;
                while(SET.find(y) != SET.end()){
                    y++;
                }
                
                length = max(length, y-x );
            }
        }
        return length;
        
        // https://leetcode.com/problems/longest-consecutive-sequence/discuss/41057/Simple-O(n)-with-Explanation-Just-walk-each-streak 
        // helped in the idea --> code khudse kar dia mene 
    }
};
/*
EXPLAINATION

x = 1 --> x= 0 (1-1) doesnt exist in set
therfore y = 2 --> found in set, therefore y++ --> y = 3
y = 3 --> found in set, therefore y++ --> y = 4
y = 4 --> found in set, therefore y++ --> y = 5
y = 5 --> not found in set --> therefore we gotta store the length of the sequence we got

currently we have x = 1 and y = 5 --> length of sequence = y-x   

therefore maintain global variable to collect the LENGTH --> Length = max(length, y-x);

*/