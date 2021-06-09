/*
����һ�����������е�Ԫ�ذ��������򣬽���ת��Ϊ�߶�ƽ��Ķ�����������
�����У�һ���߶�ƽ���������ָһ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1��
ʾ��:
�������������� [-10, -3, 0, 5, 9],
һ�����ܵĴ��ǣ�[0, -3, 9, -10, null, 5], �����Ա�ʾ��������߶�ƽ�������������
      0
     / \
   -3   9
   /   /
 -10  5
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* DFS(vector<int>& v, int start, int end) {
        if (start > end)
            return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(v[mid]);
        node->left = DFS(v, start, mid - 1);
        node->right = DFS(v, mid + 1, end);
        return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while (head != nullptr)
        {
            v.push_back(head->val);
            head = head->next;
        }
        return DFS(v, 0, v.size() - 1);
    }

};
