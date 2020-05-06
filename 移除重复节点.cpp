/*
��д���룬�Ƴ�δ���������е��ظ��ڵ㡣�����ʼ���ֵĽڵ㡣
ʾ��1:
 ���룺[1, 2, 3, 3, 2, 1]
 �����[1, 2, 3]
ʾ��2:
 ���룺[1, 1, 1, 1, 2]
 �����[1, 2]
��ʾ��
��������[0, 20000]��Χ�ڡ�
����Ԫ����[0, 20000]��Χ�ڡ�
���ף�
�������ʹ����ʱ������������ô�����
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        set<int> s;
        ListNode *prev = head, *cur = prev->next;
        s.insert(prev->val);
        while (cur)
        {
            if (s.insert(cur->val).second == true)
            {
                cur = cur->next;
                prev = prev->next;
            }
            else
            {
                prev->next = cur->next;
                if (prev != nullptr)
                    cur = prev->next;
                else
                    cur = nullptr;
            }
        }
        return head;
    }
};
