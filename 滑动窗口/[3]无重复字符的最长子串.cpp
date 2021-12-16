//
// Created by zyx on 2021/12/16.
//

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
            return s.size();

        unordered_map<char, int> window;
        int left, right, len;
        char c, d;

        left = right = len = 0;

        while (right < s.size()) {
            c = s[right];
            ++right;
            ++window[c];
            while (window[c] > 1) {
                d = s[left];
                ++left;
                --window[d];
            }
            len = max(len, right - left);
        }
        return len;
    }
};
//leetcode submit region end(Prohibit modification and deletion)