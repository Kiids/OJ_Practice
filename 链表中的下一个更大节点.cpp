/*
����һ������Ϊ n ������ head
�����б��е�ÿ���ڵ㣬������һ�� ����ڵ� ��ֵ��Ҳ����˵������ÿ���ڵ㣬�ҵ����Աߵĵ�һ���ڵ��ֵ������ڵ��ֵ �ϸ���� ����ֵ��
����һ���������� answer ������ answer[i] �ǵ� i ���ڵ�( ��1��ʼ )����һ������Ľڵ��ֵ������� i ���ڵ�û����һ������Ľڵ㣬���� answer[i] = 0 ��
ʾ�� 1��
���룺head = [2,1,5]
�����[5,5,0]
ʾ�� 2��
���룺head = [2,7,4,3,5]
�����[7,0,5,5,0]
��ʾ��
�����нڵ���Ϊ n
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
        int count = 0;
        vector<int> v;
        stack<pair<int, int>> s;
        while (head)
        {
            v.push_back(0);
            while (!s.empty() && head->val > s.top().first)
            {
                v[s.top().second] = head->val;
                s.pop();
            }
            s.push(make_pair(head->val, count++));
            head = head->next;
        }
        return v;
    }
};
