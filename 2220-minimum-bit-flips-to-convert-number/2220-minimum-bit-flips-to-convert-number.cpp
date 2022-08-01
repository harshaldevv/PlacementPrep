class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        // thora more thinking
        // if we do xor of start and goal --> and then we count the number of ones 
        // in this xorred number, we will have our answer
        
        // how to count ones in this xorred number ?
        // 1) Inbuilt function --> return __builtin_popcount(start^goal);
        // 2) without Inbuilt function -- > Brian Kernighan’s Algorithm:  
        
        int ans = 0;
        int xorr = start^goal;
        cout << xorr <<endl;
        // return __builtin_popcount(xorr);
        
       while(xorr){
           ans++;
           xorr = xorr & (xorr-1);
       }
        
        return ans;
        
//         // brute force --> convert int to binary and then increment count
//         // everytime the ith bits are different 
//         // BUT --> had i not known how to convert int to binary (from stackoverflow)
//         // i was stuck --> therefore thinking of better approach
  
//         int count = 0;
      
//         string binary1 = bitset<32>(start).to_string(); //to binary
//         string binary2 = bitset<32>(goal).to_string(); //to binary
        
//         for(int i = 0 ; i < binary1.size() ; i++){
//             if(binary1[i]  != binary2[i]){
//                 count++;
//             }
//         }
        
        
//         return count ;
        
    }
};