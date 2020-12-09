/*
����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�
ʾ�� 1:
����: 1->1->2
���: 1->2
ʾ�� 2:
����: 1->1->2->3->3
���: 1->2->3
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* p = head;
        while (p->next != NULL && p != NULL)
        {
            if (p->val == p->next->val)
                p->next = p->next->next;
            else 
                p = p->next;
        }
        return head;
    }
};
