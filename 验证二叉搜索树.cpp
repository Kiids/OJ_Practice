/*
����һ���������ĸ��ڵ� root ���ж����Ƿ���һ����Ч�Ķ�����������
��Ч �����������������£�
�ڵ��������ֻ���� С�� ��ǰ�ڵ������
�ڵ��������ֻ���� ���� ��ǰ�ڵ������
�������������������������Ҳ�Ƕ�����������
ʾ�� 1��
���룺root = [2,1,3]
�����true
ʾ�� 2��
���룺root = [5,1,4,null,null,3,6]
�����false
���ͣ����ڵ��ֵ�� 5 ���������ӽڵ��ֵ�� 4 ��
��ʾ��
���нڵ���Ŀ��Χ��[1, 10^4] ��
-2^31 <= Node.val <= 2^31 - 1
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
    bool DFS(TreeNode *node, long long lower, long long upper)
    {
        if (!node)
            return true;
        if (lower < node->val && node->val < upper)
            return DFS(node->left, lower, node->val) && DFS(node->right, node->val, upper);
        else
            return false;
    }
public:
    bool isValidBST(TreeNode* root) {
       return DFS(root, LONG_MIN, LONG_MAX);
    }
};
