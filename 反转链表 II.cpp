/*
���㵥�����ͷָ�� head ���������� left �� right ������ left <= right �����㷴ת��λ�� left ��λ�� right ������ڵ㣬���� ��ת������� ��
ʾ�� 1��
���룺head = [1,2,3,4,5], left = 2, right = 4
�����[1,4,3,2,5]
ʾ�� 2��
���룺head = [5], left = 1, right = 1
�����[5]
��ʾ��
�����нڵ���ĿΪ n
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
���ף� �����ʹ��һ��ɨ����ɷ�ת��
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ret = new ListNode(-1);
        ret->next = head;
        ListNode * pre = ret;
        for (int i = 0; i < left - 1; i++)
            pre = pre->next;
            
        ListNode * a = pre->next;
        ListNode * b;
        for (int i = 0; i < right - left; i++)
        {
            b = a->next;
            a->next = b->next;
            b->next = pre->next;
            pre->next = b;
        }
        return ret->next;
    }
};
