//
// Created by zyx on 2021/12/15.
//

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (auto i:t) ++need[i];

        int left, right, valid, start;
        left = right = valid = 0;
        int len = INT_MAX;
        char c;

        while (right < s.size()) {
            c = s[right];
            ++right;
            if (need.count(c)) {
                ++window[c];
                if (window[c] == need[c])
                    ++valid;
            }
            while (valid == need.size()) {
                c = s[left];
                if (right - left < len) {
                    len = right - left;
                    start = left;
                }

                if (need.count(c)) {
                    --window[c];
                    if (window[c] < need[c])
                        --valid;
                }
                ++left;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
//leetcode submit region end(Prohibit modification and deletion)