/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        // soln went from O(x*y) to O(xlogy) ---> to O(x+y)
        vector<vector<int>> v;
        
        int x = 1;
        int y = 1000;
        
        while ( x <= 1000 && y >0){
            int myZ = customfunction.f(x,y);
            if(myZ == z){
                v.push_back({x,y});
                x++;
                y--;
            }
            else if(myZ > z){
                y--;
            }
            else{
                x++;
            }
        }
        return v;
        
        
        
//         vector<vector<int>> v;
//         for(int i = 1 ; i <= 1000 ; i++){
            
//             // do binary search here 
//             int start = 1;
            
//             int end = 1000+1;
            
//             if(!v.empty()){  // a teensy bit optimizaiton --> see note  
//                 // cout << " here " << endl;
//                 end = v.back()[1] +1;
//             }
            
//             while(start <= end){
//                 int mid = start + (end-start)/2;
                
//                 int myZ = customfunction.f(i,mid);
//                 if(myZ == z){
//                     v.push_back({i, mid});
//                     break;
//                 }
//                 else if(myZ > z){
//                     // go left
//                     end = mid -1;
//                 }
//                 else{
//                     start = mid +1;
//                 }
//             }
//         }
        
//         return v;
    }
};