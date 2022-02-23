/*
����һ�������ͷ�ڵ� head ����ת����������ÿ���ڵ������ƶ� k ��λ�á�
ʾ�� 1��
���룺head = [1,2,3,4,5], k = 2
�����[4,5,1,2,3]
ʾ�� 2��
���룺head = [0,1,2], k = 4
�����[2,0,1]
��ʾ��
�����нڵ����Ŀ�ڷ�Χ [0, 500] ��
-100 <= Node.val <= 100
0 <= k <= 2 * 10^9
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr)
            return head;

        int n = 1;
        ListNode* iter = head;
        while (iter->next != nullptr)
        {
            iter = iter->next;
            n++;
        }
        int add = n - k % n;
        if (add == n)
            return head;
        iter->next = head;
        while (add--)
            iter = iter->next;

        ListNode* ret = iter->next;
        iter->next = nullptr;
        return ret;
    }
};
