//
// Created by zyx on 2021/12/21.
//

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int f(vector<int> &weights, int k) {
        int days = 0, sum = 0;
        for (int i = 0; i < weights.size();) {
            int cap = k;
            while (i < weights.size()) {
                if (cap < weights[i]) break;
                else cap -= weights[i];
                i++;
            }
            days++;
        }
        return days;
    }

    int shipWithinDays(vector<int> &weights, int days) {
        int left = 0, right = 0;
        for (auto i:weights) {
            left = max(left, i);
            right += i;
        }
        ++right;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int res = f(weights, mid);
            if (res <= days)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
//leetcode submit region end(Prohibit modification and deletion)