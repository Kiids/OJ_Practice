/*
����һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣
���ף����ܳ���ʹ��һ��ɨ��ʵ����
ʾ�� 1��
���룺head = [1,2,3,4,5], n = 2
�����[1,2,3,5]
ʾ�� 2��
���룺head = [1], n = 1
�����[]
ʾ�� 3��
���룺head = [1,2], n = 1
�����[1]
��ʾ��
�����н�����ĿΪ sz
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* x = new ListNode(0, head);
        ListNode* q = x;
        int l = 0;
        while (head)
        {
            l++;
            head = head->next;  
        }
        for (int i = 0; i < l - n; i++)
            q = q->next;
        q->next = q->next->next;
        ListNode* head2 = x->next;
            delete x;
        return head2;
    }
};
