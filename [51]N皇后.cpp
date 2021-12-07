//
// Created by zyx on 2021/12/7.
//

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> result;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> track(n, string(n, '.'));
        BackTrack(track, 0);
        return result;
    }
// N皇后与全排列相似 都可以使用回溯
// N皇后问题可以化为树的问题,从第一层第一个往下一层第一个开始遍历，每次遍历判断这个位置会不会打架，若打架就跳过该位置往下一个位置再判断
    void BackTrack(vector<string> &b, int row) {
        if (b.size() == row) {
            result.push_back(b);
            return;
        }
        int n = b[row].size();
        for (int col = 0; col < n; ++col) {
            // 打架判断
            if (!isBattle(b, row, col))
                continue;
            b[row][col] = 'Q';
            BackTrack(b, row + 1);
            b[row][col] = '.';
        }
    }

    bool isBattle(vector<string> &b, int row, int col) {
        int i, j;
        // 行
        for (i = 0; i < b.size(); ++i)
            if (b[row][i] == 'Q')
                return false;
        // 列
        for (i = 0; i < b.size(); ++i)
            if (b[i][col] == 'Q')
                return false;
        // 左上方
        for (i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (b[i][j] == 'Q')
                return false;
        // 右上方
        for (i = row - 1, j = col + 1; i < b.size() && j >= 0; --i, ++j)
            if (b[i][j] == 'Q')
                return false;
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
