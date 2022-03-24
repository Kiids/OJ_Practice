/*
����һ���������飬ÿ�������Ѿ����������С�
���㽫��������ϲ���һ�����������У����غϲ��������
ʾ�� 1��
���룺lists = [[1,4,5],[1,3,4],[2,6]]
�����[1,1,2,3,4,4,5,6]
���ͣ������������£�
[
  1->4->5,
  1->3->4,
  2->6
]
�����Ǻϲ���һ�����������еõ���
1->1->2->3->4->4->5->6
ʾ�� 2��
���룺lists = []
�����[]
ʾ�� 3��
���룺lists = [[]]
�����[]
��ʾ��
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] �� ���� ����
lists[i].length ���ܺͲ����� 10^4
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        ListNode *begin = new ListNode(-10001, lists[0]);
        ListNode *tmp, *now;
        for (int i = 1; i < lists.size(); i++)
        {
            tmp = begin;
            while (lists[i] != nullptr)
            {
                while (tmp->next != nullptr && lists[i]->val > tmp->next->val)
                    tmp = tmp->next;
                if (tmp->next == nullptr)
                {
                    now = lists[i];
                    lists[i] = lists[i]->next;
                    tmp->next = now;
                    now->next = nullptr;
                }
                else
                {
                    now = lists[i];
                    lists[i] = lists[i]->next;
                    now->next = tmp->next;
                    tmp->next = now;
                    tmp = tmp->next;
                }
            }
        }
        return begin->next;
    }
};
