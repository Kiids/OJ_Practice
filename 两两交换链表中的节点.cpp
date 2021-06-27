/*
����һ���������������������ڵĽڵ㣬�����ؽ����������
�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
ʾ�� 1��
���룺head = [1,2,3,4]
�����[2,1,4,3]
ʾ�� 2��
���룺head = []
�����[]
ʾ�� 3��
���룺head = [1]
�����[1]
��ʾ��
�����нڵ����Ŀ�ڷ�Χ [0, 100] ��
0 <= Node.val <= 100
���ף������ڲ��޸�����ڵ�ֵ������½����������� ��Ҳ����˵�����޸Ľڵ㱾����
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* retHead = new ListNode();
        retHead->next = head;
        ListNode* cur = retHead;

        while (cur != nullptr && cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode* f = cur;
            ListNode* s = cur->next;
            ListNode* t = s->next;

            f->next = t;
            s->next = t->next;
            t->next = s;
            cur = cur->next->next;
        }
        return retHead->next;
    }
};
