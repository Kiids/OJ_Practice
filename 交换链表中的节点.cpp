/*
给你链表的头节点 head 和一个整数 k 。
交换 链表正数第 k 个节点和倒数第 k 个节点的值后，返回链表的头节点（链表 从 1 开始索引）。
示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[1,4,3,2,5]
示例 2：
输入：head = [7,9,6,6,7,8,3,0,9,5], k = 5
输出：[7,9,6,6,8,7,3,0,9,5]
示例 3：
输入：head = [1], k = 1
输出：[1]
示例 4：
输入：head = [1,2], k = 1
输出：[2,1]
示例 5：
输入：head = [1,2,3], k = 2
输出：[1,2,3]
提示：
链表中节点的数目是 n
1 <= k <= n <= 10^5
0 <= Node.val <= 100
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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        for (auto p = head; p; p = p->next) 
            n += 1;
        auto a = head;
        for (int i = 1; i < k; i += 1)
            a = a->next;
        auto b = head;
        for (int i = 1; i < n - k + 1; i += 1)
            b = b->next;
        swap(a->val, b->val);
        return head;
    }
};
