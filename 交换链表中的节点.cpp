/*
���������ͷ�ڵ� head ��һ������ k ��
���� ���������� k ���ڵ�͵����� k ���ڵ��ֵ�󣬷��������ͷ�ڵ㣨���� �� 1 ��ʼ��������
ʾ�� 1��
���룺head = [1,2,3,4,5], k = 2
�����[1,4,3,2,5]
ʾ�� 2��
���룺head = [7,9,6,6,7,8,3,0,9,5], k = 5
�����[7,9,6,6,8,7,3,0,9,5]
ʾ�� 3��
���룺head = [1], k = 1
�����[1]
ʾ�� 4��
���룺head = [1,2], k = 1
�����[2,1]
ʾ�� 5��
���룺head = [1,2,3], k = 2
�����[1,2,3]
��ʾ��
�����нڵ����Ŀ�� n
1 <= k <= n <= 10^5
0 <= Node.val <= 100
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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        for (auto p = head; p; p = p->next) 
            n += 1;
        auto a = head;
        for (int i = 1; i < k; i += 1)
            a = a->next;
        auto b = head;
        for (int i = 1; i < n - k + 1; i += 1)
            b = b->next;
        swap(a->val, b->val);
        return head;
    }
};
