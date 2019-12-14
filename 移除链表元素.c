// 删除链表中等于给定值 val 的所有节点。
// 示例:
// 输入: 1->2->6->3->4->5->6, val = 6
// 输出: 1->2->3->4->5

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val){
    if (head == NULL)
        return NULL;
    else if (head -> val == val)
    {
        struct ListNode* newHead = removeElements(head->next, val);
        return newHead;
    }
    else
    {
        head->next = removeElements(head->next, val);
        return head;
    }
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val){
    while (head != NULL && head->val == val)
    {
        head = head->next;
    }
    if (head == NULL)
        return NULL;
    
    struct ListNode *pre = head;
    struct ListNode *p = head->next;
    
    while (p != NULL)
    {
        if (p->val == val)
            pre->next = p->next;
        else
            pre = p;
        p = p->next;
    }
    return head;
}

