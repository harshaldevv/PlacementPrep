class Solution {
public:
    
    void flipThisRow(vector<vector<int>> &grid, int r){
        int cols = grid[0].size();
        for(int j = 0 ; j < cols; j++ ){
            grid[r][j] = !grid[r][j];
        }
        return;
    }
    
    void flipThisColumn(vector<vector<int>> &grid, int c){
        int rows = grid.size();
        
        for(int i = 0 ; i < rows ; i++){
            grid[i][c] = !grid[i][c];
        }
        
        return ;
    }
    
   
    int matrixScore(vector<vector<int>>& grid) {
        /*
        
        Intution behind the greedy approach -->
        To maximise our answer from each row, we wish to have the first bit(left) se
        1 --> therefore jin rows me jinka first bit aka first column me zero hai 
        usme har row ke bits ko flip karde --> well hume technically toh first col ko hi flip 
        karna chahiye tha but ques me likha hai row me kisi bit ko flip kia toh poori row flip hogi
        
        
        Now for step 2 --> now we'll obviously avoid flipping the bits of the first column
        Therefore ab hum jo bhi kuch karenge woh second column se chalu karenge
        
        Now we wish to maximise the number of 1s in this column, kyuki 0 hoga toh 
        jab hum finally (2^something) karenge har row ke lie toh agar (2^something)*0 
        karenge toh fyda nahi lekin (2^something)*1 karenge toh fyda hoga, hamara number 
        increase hi hoga. Isliye har column me jao, agar number of ones is less than 
        the "size of row /2" --> ie "numberOfOnes <= (rows/2)" --> toh is column me
        flip all the bits 
        
        */
        
        int m = grid.size();
        int n = grid[0].size();
        
        // greedy solution --> 
        
        // step 1 --> flip all the rows whose first bit is 0
        for(int i = 0 ; i < m ; i++){
            if(grid[i][0] == 0){
                flipThisRow(grid, i);
            }
        }
        
        // printRow(grid[0]);
        
        //step 2 --> start from first column, flip all the bits of this column
        // if the number of 1s is <= row_size/2 --> and row_size = "m"
        for(int j = 1  ; j < n ; j++){
            int ones = 0;
            for(int i = 0 ; i< m ; i++){
                if(grid[i][j] == 1){
                    ones++;
                }
            }
            
            if(ones <= m/2){
                flipThisColumn(grid, j);
            }
        }
        
        // calculate sum
        int sum = 0;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    sum += (grid[i][j])*(1<<(n-j-1));
                    // 1<< n-j-1 --> means  2^(n-j-1);
                }
            }
            // cout << "sum = " << sum << endl;
        }
        
        return sum;
        
    }
};