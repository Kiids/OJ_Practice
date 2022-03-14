/*
给定一个单链表 L 的头节点 head ，单链表 L 表示为：
L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
示例 1：
输入：head = [1,2,3,4]
输出：[1,4,2,3]
示例 2：
输入：head = [1,2,3,4,5]
输出：[1,5,2,4,3]
提示：
链表的长度范围为 [1, 5 * 10^4]
1 <= node.val <= 1000
*/

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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;
        auto s = head, f = head;
        while (f && f->next)
        {
            s = s->next;
            f = f->next->next;
        }
        // s为中点
        auto pre = s, cur = s->next;
        s->next = nullptr;
        // 反转后半部分链表
        while(cur)
        {
            auto o = cur->next;
            cur->next = pre;
            pre = cur;
            cur = o;
        }
        //按照重新排列的规则将前半段链表和后半段链表组合起来
        auto p = head, q = pre;
        while (q->next)
        {
            auto o = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next;
            q = o;
        }
    }
};
