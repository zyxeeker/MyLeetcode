//
// Created by zyx on 2021/12/16.
//

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (auto i:s1) ++need[i];
        int left, right, valid;
        char c;
        valid = left = right = 0;

        while (right < s2.size()) {
            c = s2[right];
            ++right;
            if (need.count(c)) {
                ++window[c];
                if (window[c] == need[c])
                    ++valid;
            }

            while (right - left >= s1.size()) {
                if (valid == need.size())
                    return true;
                c = s2[left];
                if (need.count(c)) {
                    if (window[c] == need[c]) {
                        --valid;
                    }
                    --window[c];
                }
                ++left;
            }
#if 0
            while (valid == need.size()){
                c = s2[left];
                if(need.count(c)){
                    --window[c];
                    if(window[c]<need[c]){
                        if(right-left == s1.size())
                            return true;
                        else
                            --valid;
                    }
                }
                ++left;
            }
#endif
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)