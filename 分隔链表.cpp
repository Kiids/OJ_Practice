/*
����һ�������ͷ�ڵ� head ��һ���ض�ֵ x �������������зָ���ʹ������ С�� x �Ľڵ㶼������ ���ڻ���� x �Ľڵ�֮ǰ��
��Ӧ�� ���� ����������ÿ���ڵ�ĳ�ʼ���λ�á�
ʾ�� 1��
���룺head = [1,4,3,2,5,2], x = 3
�����[1,2,2,4,3,5]
ʾ�� 2��
���룺head = [2,1], x = 2
�����[1,2]
��ʾ��
�����нڵ����Ŀ�ڷ�Χ [0, 200] ��
-100 <= Node.val <= 100
-200 <= x <= 200
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* font = new ListNode;
        ListNode* rear = new ListNode;
        ListNode* a = font;
        ListNode* z = rear;
        ListNode* ptr = head;
        while (ptr)
        {
            if (ptr->val >= x)
            {
                z->next = ptr;
                z = ptr;
            }
            else
            {
                a->next = ptr;
                a = ptr;
            }
            ptr = ptr->next;   
        }
        z->next = NULL;
        a->next = rear->next;
        return font->next;
    }
};
