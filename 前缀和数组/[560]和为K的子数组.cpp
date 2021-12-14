//
// Created by zyx on 2021/12/14.
//

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> stat;
        int preSum, count;
        preSum = count = 0;
        stat[0] = 1;
        for (auto i:nums) {
            preSum += i;
            if (stat.find(preSum - k) != stat.end())
                count += stat[preSum - k];
            ++stat[preSum];
        }
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
