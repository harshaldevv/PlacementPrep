class Solution {
public:
    
    int BS(vector<int> &nums, int x){
        // find ceil of a number
        
        int n = nums.size();
        int l = 0;
        int r = n-1;
        
        int ans = -1; 
        
        while(l<= r){
            int mid = l + (r-l)/2;
            
            if(nums[mid] > x){
                // bada number mil gaya
                // ab lekin isse chota koi mil rahahai toh woh dhoodo (by going left)
                
                
                ans = nums[mid];
                
                // go left
                r = mid-1;
            }
            else{
                l = mid +1;
            }
        }
        
        return ans;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        
        vector<vector<int>> mapping(26);
        
        for(int i = 0 ; i < s.size() ; i++){
            mapping[ s[i] - 'a' ].push_back(i);        
        }
        
        // har word ka jahan jahan woh exist karta hai uske index mil gaye hai sorted order me 
        
        // sorted order therefore think of BS in some way or the other
        
        int ans = 0;
        
        
        for(auto &word : words){
            // cout << "word = " << word << endl;
            
            int prevIndex = -1; // for the first charac of the word, the previndex would be < 0
            // therefore i chose -1 
            
            bool wordFound = true;
            
            for(int i = 0 ; i < word.size() ; i++){
                
                // i need a number (just) greater than prevIndex --> if not found
                // this word doesnt exist in our "s", and we can move to the next word
                
                // Binary Search on the mapping of s[i] , where in i need to find 
                // "a" number just greater than previndex
                
                // binary search
            
                auto &v = mapping[ word[i]-'a'];  // & nahi lagaya toh TLE aa gaya tha
                
                
                int res = BS( v, prevIndex); // -> find ceil of a number
                
                // cout << "i = " << i;
                // cout << " , prevIndex = " << prevIndex << endl;
                // cout << "word[i] = " << word[i] << " " ;
                // cout << " res = "  << res << endl;
                
                if(res == -1){
                    
                    // nahi mila aisa koi number jo just bada ho previndex se
                    // therefore we can say that this "word" is not possible in our string "s"
                    // therefore we can break and move forward to the next word
                    
                    // cout << "here, because of word = " << word << endl;
                    wordFound = false;
                    break;
                }
                else{
                    prevIndex = res;
                }
            }
            
            if(wordFound){
                ans++;
            }
            
            // cout << endl;
        }
        
        return ans;
        
    }
};