//
// Created by zyx on 2021/12/14.
//

//leetcode submit region begin(Prohibit modification and deletion)
class NumArray {
public:
    vector<int> *preSum;
    NumArray(vector<int> &nums) {
        preSum = new vector<int>(nums.size() + 1);
        preSum->at(0) = 0;
        int i = 1;
        for (auto j:nums) {
            preSum->at(i) = preSum->at(i - 1) + j;
            ++i;
        }
    }

    int sumRange(int left, int right) {
        return preSum->at(right + 1) - preSum->at(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
//leetcode submit region end(Prohibit modification and deletion)
