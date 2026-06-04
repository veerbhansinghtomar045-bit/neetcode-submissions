class NumMatrix {
public:
    vector<vector<int>> matrix;

    NumMatrix(vector<vector<int>>& m) {
        int rows = m.size();
        int cols = m[0].size();

        // Step 1: Build row-wise prefix sums
        // Each cell stores sum from column 0 to current column in that row
        for (int i = 0; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                m[i][j] += m[i][j - 1];
            }
        }

        // Step 2: Build column-wise prefix sums
        // Now each cell stores sum from (0,0) to (i,j)
        for (int j = 0; j < cols; j++) {
            for (int i = 1; i < rows; i++) {
                m[i][j] += m[i - 1][j];
            }
        }

        // Store the prefix sum matrix
        matrix = m;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // Total sum from (0,0) to (row2,col2)
        int total = matrix[row2][col2];

        // Remove area to the left of the rectangle
        if (col1 > 0) {
            total -= matrix[row2][col1 - 1];
        }

        // Remove area above the rectangle
        if (row1 > 0) {
            total -= matrix[row1 - 1][col2];
        }

        // Add back the top-left area because it was removed twice
        if (row1 > 0 && col1 > 0) {
            total += matrix[row1 - 1][col1 - 1];
        }

        return total;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */