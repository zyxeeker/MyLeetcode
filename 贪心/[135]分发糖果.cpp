/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int result = ratings.size();
        if (result == 1) return result;

        std::vector<int> t(result, 1);

        int i = 1;
        for (;i<t.size();++i ){
            if (ratings[i] > ratings[i-1])
                t[i] = t[i-1]+1;
        }

        i = t.size()-2;
        for(; i>=0; --i){
            if(ratings[i] > ratings[i+1])
                t[i] = max(t[i+1]+1,t[i]);
        }

        return std::accumulate(t.begin(), t.end(), 0);

    }
};
// @lc code=end

