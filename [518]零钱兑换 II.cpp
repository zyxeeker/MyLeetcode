//
// Created by zyx on 2021/12/8.
//

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int change(int amount, vector<int> &coins) {
        vector<int> tmp(amount + 1, 0);
        tmp[0] = 1;
        for (auto coin:coins) {
            for (int i = coin; i < amount + 1; ++i) {
                tmp[i] += tmp[i - coin];
            }
        }
        return tmp[amount];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
