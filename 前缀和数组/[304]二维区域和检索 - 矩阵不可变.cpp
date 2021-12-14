//
// Created by zyx on 2021/12/14.
//

//leetcode submit region begin(Prohibit modification and deletion)
class NumMatrix {
public:
    vector<vector<int>> preMatrix;
    NumMatrix(vector<vector<int>> &matrix) {
        vector<vector<int>> preMatrixTmp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 1; i < matrix.size() + 1; ++i) {
            for (int j = 1; j < matrix[0].size() + 1; ++j) {
                preMatrixTmp[i][j] =
                    preMatrixTmp[i][j - 1] + preMatrixTmp[i - 1][j] + matrix[i - 1][j - 1] - preMatrixTmp[i - 1][j - 1];
            }
        }
        preMatrix = preMatrixTmp;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return preMatrix[row2 + 1][col2 + 1] - preMatrix[row2 + 1][col1] - preMatrix[row1][col2 + 1]
            + preMatrix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
//leetcode submit region end(Prohibit modification and deletion)