/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int first = 1;
        int second = 2;
        int res;
        for(int i = 2; i < n; ++i){
            res = second + first;
            first = second;
            second = res;
        }
        return res;
    }
};
// @lc code=end

