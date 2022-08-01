class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        
        
//         for(int i = 32 ; i >= 0 ; i--){
            
//         }
        
        string binary1 = bitset<32>(start).to_string(); //to binary
        string binary2 = bitset<32>(goal).to_string(); //to binary
        
        for(int i = 0 ; i < binary1.size() ; i++){
            if(binary1[i]  != binary2[i]){
                count++;
            }
        }
        
        
        return count ;
        
    }
};