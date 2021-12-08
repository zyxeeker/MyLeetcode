//
// Created by zyx on 2021/12/8.
//

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        // 备忘录
        vector<int> tmp(amount + 1, amount + 1);
        tmp[0] = 0;
        for (int i = 1; i < amount + 1; ++i) {
            int a = 0;
            for (auto coin:coins) {
                if (i - coin < 0)
                    continue;
                if (i - coin == 0) {
                    ++a;
                }
                a = tmp[i - coin] + 1;
                tmp[i] = min(a, tmp[i]);
            }
        }
        return (tmp[amount] == amount + 1) ? -1 : tmp[amount];
    }

};
//leetcode submit region end(Prohibit modification and deletion)
