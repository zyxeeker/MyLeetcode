//
// Created by zyx on 2021/12/14.
//

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        int size = 0;
        for (int i = 0; i < trips.size(); ++i)
            size = max(size, trips[i][2]);
        vector<int> diff(size, 0);
        for (int i = 0; i < trips.size(); ++i) {
            diff[trips[i][1]] += trips[i][0];
            if (trips[i][2] < size)
                diff[trips[i][2]] -= trips[i][0];
        }
        if (diff[0] > capacity)
            return false;
        for (int i = 1; i < size; ++i) {
            diff[i] = diff[i] + diff[i - 1];
            if (diff[i] > capacity)
                return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
