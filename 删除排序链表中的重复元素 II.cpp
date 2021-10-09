/*
存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。
返回同样按升序排列的结果链表。
示例 1：
输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
示例 2：
输入：head = [1,1,1,2,3]
输出：[2,3]
提示：
链表中节点数目在范围 [0, 300] 内
-100 <= Node.val <= 100
题目数据保证链表已经按升序排列
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head ->next == nullptr)
            return head;
        ListNode *ret = new ListNode, *p , *q;
        int value = head->val;
        q = ret;
        ret ->next = nullptr;
        while (head)
        {
            if (head->next == nullptr || head->next->val != value)
            {
                p = head->next;
                head->next = nullptr;
                q->next = head;
                q = q->next;
                head = p;
                value = (head != nullptr)? head->val : -1;
            }
            else
            {
                while (head != nullptr && head->val == value)
                    head = head->next;
                value = (head != nullptr)? head->val : -1;
            }
        }
        return ret->next;
    }
};
