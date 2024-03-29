/*
给定一个长度为 n 的链表 head
对于列表中的每个节点，查找下一个 更大节点 的值。也就是说，对于每个节点，找到它旁边的第一个节点的值，这个节点的值 严格大于 它的值。
返回一个整数数组 answer ，其中 answer[i] 是第 i 个节点( 从1开始 )的下一个更大的节点的值。如果第 i 个节点没有下一个更大的节点，设置 answer[i] = 0 。
示例 1：
输入：head = [2,1,5]
输出：[5,5,0]
示例 2：
输入：head = [2,7,4,3,5]
输出：[7,0,5,5,0]
提示：
链表中节点数为 n
1 <= n <= 10^4
1 <= Node.val <= 10^9
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
    vector<int> nextLargerNodes(ListNode* head) {
        int count = 0;                              // 计数 下标
        vector<int> v;
        stack<pair<int, int>> s;                    // first -> val，second -> 下标
        while (head)
        {
            v.push_back(0);                         // 数组+0，保证长度&后无更大的值时为0
            while (!s.empty() && head->val > s.top().first)
            {
                v[s.top().second] = head->val;
                s.pop();
            }
            s.push(make_pair(head->val, count++));  // count++计数
            head = head->next;
        }
        return v;
    }
};
