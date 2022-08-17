class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string ans = "";
        
        int l1 = 0;
        int l2 = 0;
        
        bool first = true;
        while( (l1 < word1.size()) && (l2 < word2.size()) ){
            if(first){
                ans += word1[l1];
                l1++;
                
            }
            else{
                ans += word2[l2];
                l2++;
            }
            
            first = !first ;
        }
        
        while(l1 < word1.size() ){
            ans+=word1[l1++];
        }
        
        while(l2 < word2.size() ){
            ans+=word2[l2++];
        }
        
        
        return ans;
        
        
    }
};