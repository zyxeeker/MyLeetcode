//
// Created by zyx on 2021/12/9.
//

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        map<string, bool> visited;
        deque<string> not_visited;
        for (auto i: deadends)
            visited[i] = true;
        not_visited.push_back("0000");
        int steps = 0;
        while (!not_visited.empty()) {
            int size = not_visited.size();
            for (int i = 0; i < size; ++i) {
                string tmp = not_visited.front();
                not_visited.pop_front();

                if (visited[tmp]) continue;
                visited[tmp] = true;

                if (tmp == target) return steps;

                for (int j = 0; j < 4; ++j) {
                    string str;
                    str = doUp(tmp, j);
                    if (!visited[str])
                        not_visited.push_back(str);
                    str = doDown(tmp, j);
                    if (!visited[str])
                        not_visited.push_back(str);
                }
            }
            ++steps;
        }
        return -1;
    }

    string doUp(string str, int index) {
        if (str[index] == '9')
            str[index] = '0';
        else
            ++str[index];
        return str;
    }
    string doDown(string str, int index) {
        if (str[index] == '0')
            str[index] = '9';
        else
            --str[index];
        return str;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
