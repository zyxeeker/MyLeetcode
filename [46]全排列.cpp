//
// Created by zyx on 2021/12/7.
//

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int> &nums) {
        vector<int> track;
        backTrack(nums, track);
        return result;
    }

    void backTrack(vector<int> a, vector<int> b) {
        if (a.size() == b.size()) {
            result.push_back(b);
            return;
        }
        for (auto i = a.begin(); i != a.end(); ++i) {
            // 判断路径中是否含有当前的数据，若有跳过循环，
            if (count(b.begin(), b.end(), *i))
                continue;
            // 没有则进入递归，进入递归后上层函数的指针停在进入递归的值
            b.push_back(*i);
            backTrack(a, b);
            // 递归完成后，移除最后一个值也就是进入之前进入的值，然后继续循环带入后面的值
            b.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)