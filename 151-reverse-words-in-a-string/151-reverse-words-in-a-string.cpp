class Solution {
public:
    void reversal(string &s, int i, int j){
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return ;
    }
    string reverseWords(string s) {
        
        // now we'll optimise on the space --> bring down to O(1)
        
        // brute force  
        // TC - O(n), SC - O(n)
        
        // store all the words in a vector
        // reverse the vector 
        // push all the strings in the answer string with a space
        
        // PS -  pop out the last space 
        
        
        vector<string> words;
        stringstream ss (s);
        string temp;
        while(ss >>temp){
            words.push_back(temp);
        }
        
        reverse(words.begin(), words.end());
        
        string ans = "";
        
        for(auto &x : words){
            ans += x;
            ans += " ";
        }
        
        
        ans.pop_back() ;  // --> the extra space at the end
        
        return ans;
        
    }
};