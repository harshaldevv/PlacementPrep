class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int> v(2, -1);
        
        // our target is to find a candy pair whose difference is exactly x/2
        
        int A = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int B = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int diff = A-B;
        
        unordered_set<int> s(aliceSizes.begin(), aliceSizes.end());
        
        for(int i = 0 ;  i < bobSizes.size() ; i++){
            
            int y = bobSizes[i];
            int x = y + diff/2;
            
            if(s.find(x) != s.end()){
                v[0] = x ;
                v[1] = y;
                return v;
            }
            
        }
        
        return v;
        
        

//         // gives TLE
        
//         for(int i = 0 ; i< aliceSizes.size(); i++){
//             for(int j = 0 ; j < bobSizes.size() ; j++ ){
//                 if(aliceSizes[i] - bobSizes[j] == diff/2){
//                     v[0] = aliceSizes[i];
//                     v[1] = bobSizes[j];
//                     return v;
//                 }
//             }
//         }
        
//         return v;
        
    }
};