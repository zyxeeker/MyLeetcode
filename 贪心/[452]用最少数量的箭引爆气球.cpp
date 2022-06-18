/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 1) return 1;

        std::sort(points.begin(), points.end(),[](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });

        int start = points[0][0];
        int end = points[0][1];

        int result = 0;

        for (int i = 1; i <points.size(); ++i){
            if (points[i][0] <= end){
                start = points[i][0];
                end = min(end, points[i][1]);
            }else{
                start = points[i][0];
                end = points[i][1];
                ++result;
            }
        }
        ++result;
        
        return result;

    }
};
// @lc code=end

