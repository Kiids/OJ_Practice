/*
����һ�������� L ��ͷ�ڵ� head �������� L ��ʾΪ��
L0 �� L1 �� �� �� Ln - 1 �� Ln
�뽫���������к��Ϊ��
L0 �� Ln �� L1 �� Ln - 1 �� L2 �� Ln - 2 �� ��
����ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
ʾ�� 1��
���룺head = [1,2,3,4]
�����[1,4,2,3]
ʾ�� 2��
���룺head = [1,2,3,4,5]
�����[1,5,2,4,3]
��ʾ��
����ĳ��ȷ�ΧΪ [1, 5 * 10^4]
1 <= node.val <= 1000
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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;
        auto s = head, f = head;
        while (f && f->next)
        {
            s = s->next;
            f = f->next->next;
        }
        // sΪ�е�
        auto pre = s, cur = s->next;
        s->next = nullptr;
        // ��ת��벿������
        while(cur)
        {
            auto o = cur->next;
            cur->next = pre;
            pre = cur;
            cur = o;
        }
        //�����������еĹ���ǰ�������ͺ��������������
        auto p = head, q = pre;
        while (q->next)
        {
            auto o = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next;
            q = o;
        }
    }
};
