class Solution {
public:
    int kthGrammar(int n, int k) {
        // return 1;  //pass 32/55 cases
        // return 0;  //passes 23/55 cases xD
        
        if(n== 1 && k ==1){
            return 0;
        }
        
        int length = pow(2,n-1);
        int mid = length/2;
        
        if(k <= mid){
            return kthGrammar(n-1, k);
        }
        else{
            return !kthGrammar(n-1, k-mid);
        }
        
        
        
    }
};