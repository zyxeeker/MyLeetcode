//
// Created by zyx on 2021/12/21.
//

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int f(vector<int> &piles, int k) {
        int hours = 0;
        for (int i = 0; i < piles.size(); ++i) {
            hours += piles[i] / k;
            if (piles[i] % k > 0)
                ++hours;
        }
        return hours;
    }
    int minEatingSpeed(vector<int> &piles, int h) {
        int left = 1, right = 1000000000 + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (f(piles, mid) <= h)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
