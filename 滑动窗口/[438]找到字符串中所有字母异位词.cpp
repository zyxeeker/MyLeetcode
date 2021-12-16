//
// Created by zyx on 2021/12/16.
//

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        vector<int> pos;
        for (auto i:p) ++need[i];

        int left, right, valid;
        char c;
        valid = left = right = 0;

        while (right < s.size()) {
            c = s[right];
            ++right;
            if (need.count(c)) {
                ++window[c];
                if (window[c] == need[c])
                    ++valid;
            }
            while (right - left >= p.size()) {
                c = s[left];
                if (valid == need.size()) {
                    pos.push_back(left);
                }
                if (need.count(c)) {
                    if (need[c] == window[c])
                        --valid;
                    --window[c];
                }
                ++left;
            }
        }
        return pos;
    }
};
//leetcode submit region end(Prohibit modification and deletion)