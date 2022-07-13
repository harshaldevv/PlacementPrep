class Solution {
public:
    bool isRobotBounded(string instructions) {
        
        int currx = 0;
        int curry = 0;
        int faceInWhichDirection = 0 ;  
        
        // 0 -> north (currx, curry +1)
        // 1 -> east (currx-1, curry)
        // 2 -> south, currx, curry -1
        // 3 - west (currx +1, curry)
        
        
        for(auto &instruct : instructions){
            if(instruct == 'G'){
                if(faceInWhichDirection == 0){
                    currx +=0;
                    curry +=1;
                }
                else if(faceInWhichDirection == 1){
                    currx -=1;
                    curry +=0;
                }
                else if(faceInWhichDirection == 2){
                    currx+= 0;
                    curry -=1;
                }
                else if(faceInWhichDirection == 3){
                    currx +=1;
                    curry += 0;
                }
            }
            else if(instruct == 'L'){
                faceInWhichDirection = faceInWhichDirection +1;
                faceInWhichDirection = faceInWhichDirection%4;
            }
            else if(instruct == 'R'){
                faceInWhichDirection = faceInWhichDirection - 1 + ( +4);  // +4 isliye cuz maanlo -ve ho gaya isliye +4 toh bring in the +ve bounds
                faceInWhichDirection = faceInWhichDirection%4;
            }
        }
        
        // bas hints dekhe ki kya kar skte hai, lekin code poora kar dia
        
        // The robot stays in the circle if and only if (looking at the final vector) 
        // it changes direction (ie. doesn't stay pointing north), or it moves 0.
        // Note north = 0 , therefore ive checked faceindirection with 0(north), as our
        // initial direction was north (0);
        
        return faceInWhichDirection != 0 || (currx == 0 && curry == 0);
        
    }
};