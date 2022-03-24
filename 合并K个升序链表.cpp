/*
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。
示例 1：
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
示例 2：
输入：lists = []
输出：[]
示例 3：
输入：lists = [[]]
输出：[]
提示：
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] 按 升序 排列
lists[i].length 的总和不超过 10^4
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
