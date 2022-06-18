/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int result = 0;
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int index = 0;
        for (auto &i : g){
            for (; index < s.size(); ++index){
                if (i <= s[index]){
                    ++result;
                    ++index;
                    break;
                }
            }
        }
        return result;
    }
};
// @lc code=end

