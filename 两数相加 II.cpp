/*
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。
示例1：
输入：l1 = [7,2,4,3], l2 = [5,6,4]
输出：[7,8,0,7]
示例2：
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[8,0,7]
示例3：
输入：l1 = [0], l2 = [0]
输出：[0]
提示：
链表的长度范围为 [1, 100]
0 <= node.val <= 9
输入数据保证链表代表的数字无前导 0
进阶：如果输入链表不能修改该如何处理？换句话说，不能对列表中的节点进行翻转。
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> a, b;
        int sub = 0;
        while (l1)
        {
            a.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            b.push(l2->val);
            l2 = l2->next;
        }
        auto pre = l1 = nullptr, head = pre;
        while (a.size() || b.size() || sub) 
        {
            if (a.size())
            {
                sub += a.top();
                a.pop();
            }
            if (b.size())
            {
                sub += b.top();
                b.pop();
            }
            pre = new ListNode(sub % 10);
            sub = sub / 10;
            pre->next = head;
            head = pre;
        }
        return head;
    }
};
