/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int result = 0;
        if (intervals.size()==1) return result;

        std::sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1; i<intervals.size(); ++i){
            if(intervals[i][1] > end && intervals[i][0] >= end)
                end = intervals[i][1];
            else
                ++result;
        }

        return result;
    }
};
// @lc code=end

