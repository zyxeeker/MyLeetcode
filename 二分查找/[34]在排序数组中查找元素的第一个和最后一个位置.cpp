//
// Created by zyx on 2021/12/17.
//

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int mark = -1, left = 0, right = nums.size() - 1;
        vector<int> res{-1, -1};

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                mark = mid;
                break;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        if (mark == -1)
            return res;

        res[0] = res[1] = mark;
        int siz = nums.size() - mark;
        int end = max(mark, siz);
        for (int i = 1; i < end; ++i) {
            if (mark - i >= 0 && nums[mark - i] == target)
                --res[0];
            if (mark + i <= nums.size() - 1 && nums[mark + i] == target)
                ++res[1];
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)