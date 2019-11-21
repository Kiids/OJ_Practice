// ��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ� 
// ʾ����
// ���룺1->2->4, 1->3->4
// �����1->1->2->3->4->4

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;
    struct ListNode *head, *tail;
    if (l1->val < l2->val)
    {
        head = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        l2 = l2->next;
    }
    tail = head;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val > l2->val)
        {
            tail->next = l2;
            l2 = l2->next;
        }
        else
        {
            tail->next = l1;
            l1 = l1->next;
        }
        tail = tail->next;
    }
    if (l1 != NULL)
        tail->next = l1;
    else if (l2 != NULL)
        tail->next = l2;
    return head;
}

