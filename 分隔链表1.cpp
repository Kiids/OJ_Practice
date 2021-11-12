/*
����һ��ͷ���Ϊ head �ĵ������һ������ k ���������һ���㷨������ָ�Ϊ k �������Ĳ��֡�
ÿ���ֵĳ���Ӧ�þ����ܵ���ȣ����������ֵĳ��Ȳ�಻�ܳ��� 1 ������ܻᵼ����Щ����Ϊ null ��
�� k ������Ӧ�ð����������г��ֵ�˳�����У���������ǰ��Ĳ��ֵĳ���Ӧ�ô��ڻ�������ں���ĳ��ȡ�
����һ�������� k ������ɵ����顣
ʾ�� 1��
���룺head = [1,2,3], k = 5
�����[[1],[2],[3],[],[]]
���ͣ�
��һ��Ԫ�� output[0] Ϊ output[0].val = 1 ��output[0].next = null ��
���һ��Ԫ�� output[4] Ϊ null ��������Ϊ ListNode ���ַ�����ʾ�� [] ��
ʾ�� 2��
���룺head = [1,2,3,4,5,6,7,8,9,10], k = 3
�����[[1,2,3,4],[5,6,7],[8,9,10]]
���ͣ�
���뱻�ֳ��˼��������Ĳ��֣�����ÿ���ֵĳ��������� 1 ��ǰ�沿�ֵĳ��ȴ��ڵ��ں��沿�ֵĳ��ȡ�
��ʾ��
�����нڵ����Ŀ�ڷ�Χ [0, 1000]
0 <= Node.val <= 1000
1 <= k <= 50
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* cur = head;
        vector<ListNode*> v(k, NULL);
        int l = 0, a = 0, b = 0;
        while (cur)
        {
            l++;
            cur = cur->next;
        }
        a = l / k;
        b = l % k;
        cur = head;
        for (int i = 0; i < k && cur; i++)
        {
            v[i] = cur;
            for (int j = 1; j < a + (i < b ? 1 : 0); j++)
                cur = cur->next;
            ListNode* t = cur->next;
            cur->next = NULL;
            cur = t;
        }
        return v;
    }
};
