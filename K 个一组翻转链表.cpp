/*
����һ������ÿ k ���ڵ�һ����з�ת�����㷵�ط�ת�������
k ��һ��������������ֵС�ڻ��������ĳ��ȡ�
����ڵ��������� k ������������ô�뽫���ʣ��Ľڵ㱣��ԭ��˳��
���ף�
��������һ��ֻʹ�ó�������ռ���㷨�������������
�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʽ��нڵ㽻����
ʾ�� 1��
���룺head = [1,2,3,4,5], k = 2
�����[2,1,4,3,5]
ʾ�� 2��
���룺head = [1,2,3,4,5], k = 3
�����[3,2,1,4,5]
ʾ�� 3��
���룺head = [1,2,3,4,5], k = 1
�����[1,2,3,4,5]
ʾ�� 4��
���룺head = [1], k = 1
�����[1]
��ʾ��
�б��нڵ�������ڷ�Χ sz ��
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto isOk = head;
        for (int i = 0; i < k; i++)
        {
            if (!isOk)
                return head;
            isOk = isOk->next;
        }
        ListNode *cur = head, *pre = nullptr, *next = nullptr;
        for (int i = 0; i < k; i++)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur, cur = next;
        }
        head->next = reverseKGroup(cur, k);
        return pre;
    }
};
