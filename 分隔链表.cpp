/*
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
你应当 保留 两个分区中每个节点的初始相对位置。
示例 1：
输入：head = [1,4,3,2,5,2], x = 3
输出：[1,2,2,4,3,5]
示例 2：
输入：head = [2,1], x = 2
输出：[1,2]
提示：
链表中节点的数目在范围 [0, 200] 内
-100 <= Node.val <= 100
-200 <= x <= 200
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* font = new ListNode;
        ListNode* rear = new ListNode;
        ListNode* a = font;
        ListNode* z = rear;
        ListNode* ptr = head;
        while (ptr)
        {
            if (ptr->val >= x)
            {
                z->next = ptr;
                z = ptr;
            }
            else
            {
                a->next = ptr;
                a = ptr;
            }
            ptr = ptr->next;   
        }
        z->next = NULL;
        a->next = rear->next;
        return font->next;
    }
};
