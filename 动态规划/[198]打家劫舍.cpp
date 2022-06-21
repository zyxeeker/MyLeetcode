/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
        int prev_max = 0, prev_tmp = 0, cur_max;
        for (int i = 0; i < nums.size(); ++i){
            cur_max = max(prev_max, prev_tmp + nums[i]);
            prev_tmp = prev_max;
            prev_max = cur_max;
        }
        return cur_max;
    }
};
// @lc code=end

