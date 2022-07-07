/*
����һ�������ͷ�ڵ� head ��ɾ�� ����� �м�ڵ� ���������޸ĺ�������ͷ�ڵ� head ��
����Ϊ n ������м�ڵ��Ǵ�ͷ�����  n / 2  ���ڵ㣨�±�� 0 ��ʼ��������  x  ��ʾС�ڻ���� x �����������
���� n = 1��2��3��4 �� 5 ��������м�ڵ���±�ֱ��� 0��1��1��2 �� 2 ��
ʾ�� 1��
���룺head = [1,3,4,7,1,2,6]
�����[1,3,4,1,2,6]
���ͣ�
��ͼ��ʾ�����������ڵ���±�ֱ��ע��ÿ���ڵ���·���
���� n = 7 ��ֵΪ 7 �Ľڵ� 3 ���м�ڵ㣬�ú�ɫ��ע��
���ؽ��Ϊ�Ƴ��ڵ��������� 
ʾ�� 2��
���룺head = [1,2,3,4]
�����[1,2,4]
���ͣ�
��ͼ��ʾ����������
���� n = 4 ��ֵΪ 3 �Ľڵ� 2 ���м�ڵ㣬�ú�ɫ��ע��
ʾ�� 3��
���룺head = [2,1]
�����[2]
���ͣ�
��ͼ��ʾ����������
���� n = 2 ��ֵΪ 1 �Ľڵ� 1 ���м�ڵ㣬�ú�ɫ��ע��
ֵΪ 2 �Ľڵ� 0 ���Ƴ��ڵ� 1 ��ʣ�µ�Ψһһ���ڵ㡣
��ʾ��
�����нڵ����Ŀ�ڷ�Χ [1, 10^5] ��
1 <= Node.val <= 10^5
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* x = new ListNode(-1);
        x->next = head;
        
        ListNode *slow = x, *fast = x->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return x->next;
    }
};
