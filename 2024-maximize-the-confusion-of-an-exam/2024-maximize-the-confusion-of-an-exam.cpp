class Solution {
public:
    int ulta(string answerKey, int k) {
        int truecount = 0;
        int l = 0;
        int r = 0;
        int n = answerKey.size();
        int ans = 0;
        
        while(r < n){
            if(answerKey[r] == 'F'){
                truecount++;
            }
            
            if(truecount > k){
                
                while(truecount > k){
                    if(answerKey[l] == 'F'){
                        truecount--;
                    }
                    l++;
                }
                
            }
            
            ans = max(ans, r-l+1);
            r++;
        }
        
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        // true ko false karo
        
        int truecount = 0;
        int l = 0;
        int r = 0;
        int n = answerKey.size();
        int ans = 0;
        
        while(r < n){
            if(answerKey[r] == 'T'){
                truecount++;
            }
            
            if(truecount > k){
                
                while(truecount > k){
                    if(answerKey[l] == 'T'){
                        truecount--;
                    }
                    l++;
                }
                
            }
            
            ans = max(ans, r-l+1);
            r++;
        }
        
        // return ans;
        
        int doosra = ulta(answerKey, k);
        
        return max(ans, doosra);
        
        
    }
};