//
// Created by zyx on 2021/12/14.
//

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
        vector<int> diff(n, 0);
        for (int i = 0; i < bookings.size(); ++i) {
            diff[bookings[i][0] - 1] += bookings[i][2];
            if (bookings[i][1] < n)
                diff[bookings[i][1]] -= bookings[i][2];
        }
        for (int i = 1; i < n; ++i) {
            diff[i] = diff[i] + diff[i - 1];
        }
        return diff;
    }
};
//leetcode submit region end(Prohibit modification and deletion)