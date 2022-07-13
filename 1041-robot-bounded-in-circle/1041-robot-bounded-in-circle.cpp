class Solution {
public:
    bool isRobotBounded(string instructions) {
        // therefore if their change in the direction vector, after 
        int currx = 0;
        int curry = 0;
        int faceInWhichDirection = 0 ;  
        
        // 1 -> north (currx, curry +1)
        // 2 -> east (currx-1, curry)
        // 3 -> south, currx, curry -1
        // 4 - west (currx +1, curry)
        
        
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
                faceInWhichDirection = faceInWhichDirection - 1 + ( +4);
                faceInWhichDirection = faceInWhichDirection%4;
            }
        }
        
        // bas hints dekhe ki kya kar skte hai, lekin code poora kar dia
        return faceInWhichDirection != 0 || (currx == 0 && curry == 0);
        
    }
};