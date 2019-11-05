// ��תһ��������
// ʾ��:
// ����: 1->2->3->4->5->NULL
// ���: 5->4->3->2->1->NULL
// ����:
// ����Ե�����ݹ�ط�ת�������ܷ������ַ����������⣿

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* newhead = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        struct ListNode* next = cur->next;
        cur->next = newhead;
        newhead = cur;
        cur = next;
    }
    return newhead;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode *n1, *n2, *n3;
    n1 = head;
    n2 = n1->next;
    n3 = n2->next;
    n1->next = NULL;
    while (n2)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3)
            n3 = n3->next;
    }
    return n1;
}

