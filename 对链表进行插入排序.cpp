/*
�������������ͷ head ��ʹ�� �������� ������������򣬲����� ����������ͷ ��
�������� �㷨�Ĳ���:
���������ǵ����ģ�ÿ��ֻ�ƶ�һ��Ԫ�أ�ֱ������Ԫ�ؿ����γ�һ�����������б�
ÿ�ε����У���������ֻ�������������Ƴ�һ���������Ԫ�أ��ҵ������������ʵ���λ�ã���������롣
�ظ�ֱ�������������ݲ�����Ϊֹ��
�����ǲ��������㷨��һ��ͼ��ʾ��������������б�(��ɫ)���ֻ�����б��еĵ�һ��Ԫ�ء�ÿ�ε���ʱ��������������ɾ��һ��Ԫ��(��ɫ)�����͵ز�����������б��С�
��������в�������
ʾ�� 1��
����: head = [4,2,1,3]
���: [1,2,3,4]
ʾ�� 2��
����: head = [-1,5,3,4,0]
���: [-1,0,3,4,5]
��ʾ��
�б��еĽڵ����� [1, 5000]��Χ��
-5000 <= Node.val <= 5000
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* x = new ListNode(0);
        x->next = head;
        ListNode* cur = head->next;
        ListNode* p = head;
        ListNode* pre = x;

        ListNode* last = head;
        while (cur != NULL)
        {
            pre = x;
            p = x->next;
            while (p != cur && p->val <= cur->val)
            {
                pre = p;
                p = p->next;
            }
            if (p == cur)
            {
                last = cur;
                cur = cur->next;
            }
            else
            {
                last->next = cur->next;
                cur->next = pre->next;
                pre->next = cur;
                cur = last->next;
            }
        }
        return x->next;
    }
};
