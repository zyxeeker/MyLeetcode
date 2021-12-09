//
// Created by zyx on 2021/12/9.
//

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        deque < TreeNode * > not_visited;
        int depth = 1;
        not_visited.push_back(root);
        while (1) {
            int size = not_visited.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *tmp = not_visited.front();
                if (tmp->right == nullptr && tmp->left == nullptr)
                    return depth;
                if (tmp->right != nullptr)
                    not_visited.push_back(tmp->right);
                if (tmp->left != nullptr)
                    not_visited.push_back(tmp->left);
                not_visited.pop_front();
            }
            ++depth;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)