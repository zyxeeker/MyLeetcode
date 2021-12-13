//
// Created by zyx on 2021/12/13.
//

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *p1;
        ListNode *p2;
        ListNode *root;
        root = dummy;
        p1 = list1;
        p2 = list2;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val > p2->val) {
                root->next = p2;
                p2 = p2->next;
            } else {
                root->next = p1;
                p1 = p1->next;
            }
            root = root->next;
        }
        if (p1 != nullptr)
            root->next = p1;
        if (p2 != nullptr)
            root->next = p2;
        return dummy->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)