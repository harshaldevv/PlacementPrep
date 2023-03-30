class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //hci research
        vector<int> result;
        int m = matrix.size(), n = matrix[0].size();
        int rowStart = 0, rowEnd = m - 1, colStart = 0, colEnd = n - 1;

        while (rowStart <= rowEnd && colStart <= colEnd) {
            // Traverse Right
            for (int i = colStart; i <= colEnd; i++)
                result.push_back(matrix[rowStart][i]);

            // Traverse Down
            for (int i = rowStart + 1; i <= rowEnd; i++)
                result.push_back(matrix[i][colEnd]);

            // Traverse Left
            if (rowStart < rowEnd) {
                for (int i = colEnd - 1; i >= colStart; i--)
                    result.push_back(matrix[rowEnd][i]);
            }

            // Traverse Up
            if (colStart < colEnd) {
                for (int i = rowEnd - 1; i > rowStart; i--)
                    result.push_back(matrix[i][colStart]);
            }

            rowStart++;
            rowEnd--;
            colStart++;
            colEnd--;
        }

        return result;
    }
};
