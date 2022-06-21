/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        std::vector<int> tmp;
        for(int i = 1;i < prices.size(); ++i){
            tmp.push_back(prices[i] - prices[i-1]);
        }
        for(int i = 0;i<tmp.size();++i){
            if (tmp[i] >= 0){
                res += tmp[i];
            }
        }
        return res;

    }
};
// @lc code=end

