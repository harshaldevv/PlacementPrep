class Solution {
public:
    
//     bool possible(int r, int c, int n , vector<string> &board){
        
//         // check left side (column right to left)
//         for(int i = c ; i >= 0 ; i--){
//             if(board[r][i] == 'Q'){
//                 return false;
//             }    
//         }
        
//         //check left upper diagonal
//         int tempR = r;
//         int tempC = c;
//         while(tempR>=0 && tempC>=0){
//             if(board[tempR][tempC] == 'Q'){
//                 return false;
//             }
//             tempR--;
//             tempC--;
//         }
        
        
//         // check left lower diagonal
//         tempR = r;
//         tempC = c;
//         while(tempR<n && tempC>=0){
//             if(board[tempR][tempC] == 'Q'){
//                 return false;
//             }
//             tempR++;
//             tempC--;
//         }
        
//         return true;

        
        
//     }
    
//     void recursion(int n, int currCol, vector<vector<string>> &ans, vector<string> &board){
//         if(currCol > n){
//             return ;
//         }
        
//         if(currCol == n){
//             ans.push_back(board) ;
//             return ;
//         }
        
//         for(int currRow = 0 ; currRow < n ; currRow++){
//             // iterating rows
//             // cout << "currRow = " << currRow << endl;
//             if(possible(currRow, currCol, n, board)){
//                 board[currRow][currCol] = 'Q';
//                 recursion(n, currCol +1, ans, board);
//                 board[currRow][currCol] = '.';
//             }
//         }
//         return ;
//     }
    
    
    void recursion(int n, int currcol, vector<vector<string>> &ans, vector<string> &board, vector<int> &left, vector<int> &up, vector<int> &low){
        
        if(currcol > n){
            return;
        }
        if(currcol == n){
            ans.push_back(board);
            return ;
        }
        
        for(int currrow = 0 ; currrow < n ; currrow++){
            if(left[currrow] == 0 && up[currrow + currcol] == 0 && low[n-1 + currcol - currrow] == 0){ 
                // this if condn replaces the possible() function
                
                board[currrow][currcol] = 'Q';
                left[currrow] = 1;
                up[currrow + currcol] = 1;
                low[n-1 + currcol - currrow] = 1;
                
                recursion(n, currcol+1, ans, board, left, up, low);
                
                board[currrow][currcol] = '.';
                left[currrow] = 0;
                up[currrow + currcol] = 0;
                low[n-1 + currcol - currrow] = 0;
                
            }
        }
        return ;
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        
        vector<vector<string>> ans;
        vector<string> board(n,  string (n, '.') );
        
        
        // recursion(n, 0, ans, board);
        
        //optimization 
        // --> to avoid calling possible() again and again
        // as possible is O(3n) and for it runs n times in recursion() func
        // therefore leading to O(n^2) complexity
        
        // to lower this complexity to O(n) , we are doing this opitization
        vector<int> left(n,0);
        vector<int> upper(2*n-1,0); // upper diagonal
        vector<int> lower(2*n-1,0); // lower diagonal
        
        recursion(n,0, ans, board, left, upper, lower);
        // OPTIMZATION VIDEO - Striver N queen video
        // https://youtu.be/i05Ju7AftcM?t=2104
        
        return ans;
        
        
        
    }
};