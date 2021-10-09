/*
����һ�����������е�����������������ͷ�ڵ� head ������ɾ�����������д��������ظ�����Ľڵ㣬ֻ����ԭʼ������ û���ظ����� �����֡�
����ͬ�����������еĽ������
ʾ�� 1��
���룺head = [1,2,3,3,4,4,5]
�����[1,2,5]
ʾ�� 2��
���룺head = [1,1,1,2,3]
�����[2,3]
��ʾ��
�����нڵ���Ŀ�ڷ�Χ [0, 300] ��
-100 <= Node.val <= 100
��Ŀ���ݱ�֤�����Ѿ�����������
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head ->next == nullptr)
            return head;
        ListNode *ret = new ListNode, *p , *q;
        int value = head->val;
        q = ret;
        ret ->next = nullptr;
        while (head)
        {
            if (head->next == nullptr || head->next->val != value)
            {
                p = head->next;
                head->next = nullptr;
                q->next = head;
                q = q->next;
                head = p;
                value = (head != nullptr)? head->val : -1;
            }
            else
            {
                while (head != nullptr && head->val == value)
                    head = head->next;
                value = (head != nullptr)? head->val : -1;
            }
        }
        return ret->next;
    }
};
