/*
�������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣
����ɾ����������ͷ�ڵ㡣
ע�⣺����Ա�ԭ���иĶ�
ʾ�� 1:
����: head = [4,5,1,9], val = 5
���: [4,1,9]
����: ������������ֵΪ?5?�ĵڶ����ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 1 -> 9.
ʾ�� 2:
����: head = [4,5,1,9], val = 1
���: [4,5,9]
����: ������������ֵΪ?1?�ĵ������ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 5 -> 9.
˵����
��Ŀ��֤�����нڵ��ֵ������ͬ
��ʹ�� C �� C++ ���ԣ��㲻��Ҫ free �� delete ��ɾ���Ľڵ�
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
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val)
            return head->next;

        ListNode *cur = head->next, *prev = head;
        while (cur->val != val && cur)
        {
            cur = cur->next;
            prev = prev->next;
        }
        prev->next = cur->next;
        return head;
    }
};
