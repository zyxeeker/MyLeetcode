/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        std::sort(people.begin(), people.end(), [](std::vector<int> &a, std::vector<int> &b){
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });
        
        std::list<std::vector<int>> tmp;
        for(auto i : people){
            auto it = tmp.begin();
            std::advance(it, i[1]);
            tmp.insert(it, i);
        }

        return std::vector<std::vector<int>>(tmp.begin(), tmp.end());

    }
};
// @lc code=end

