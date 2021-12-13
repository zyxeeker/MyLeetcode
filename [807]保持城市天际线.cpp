//
// Created by zyx on 2021/12/13.
//

// Daily Problem

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
#if 0
        vector<int> x;
        vector<int> y;
        int x_tmp,y_tmp,x_size,y_size,sum;
        sum = x_tmp = y_tmp = 0;

        x_size = grid[0].size();
        y_size = grid.size();

        for(auto i : grid){
            for (auto j:i){
                if (j>x_tmp)
                    x_tmp = j;
            }
            x.push_back(x_tmp);
            x_tmp = 0;
        }
        for(int i = 0;i<x_size;++i){
            for(int j = 0;j<y_size;++j){
                if(grid[j][i]>y_tmp)
                    y_tmp = grid[j][i];
            }
            y.push_back(y_tmp);
            y_tmp = 0;
        }
#endif
        int x_size, y_size, sum;
        sum = 0;
        x_size = grid[0].size();
        y_size = grid.size();

        vector<int> x(x_size);
        vector<int> y(y_size);

        for (int i = 0; i < y_size; ++i) {
            for (int j = 0; j < x_size; ++j) {
                x[i] = max(x[i], grid[i][j]);
                y[j] = max(y[j], grid[i][j]);
            }
        }

        for (int i = 0; i < y_size; ++i) {
            for (int j = 0; j < x_size; ++j) {
                int t = min(x[j], y[i]);
                sum += (t - grid[i][j]);
            }
        }
        return sum;
    }

};
//leetcode submit region end(Prohibit modification and deletion)