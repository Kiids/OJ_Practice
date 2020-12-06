/*
����һ�����нڵ�Ϊ�Ǹ�ֵ�Ķ�����������������������������ڵ�Ĳ�ľ���ֵ����Сֵ��
ʾ����
���룺
   1
    \
     3
    /
   2
�����
1
���ͣ�
��С���Բ�Ϊ 1������ 2 �� 1 �Ĳ�ľ���ֵΪ 1������ 2 �� 3����
��ʾ��
���������� 2 ���ڵ㡣
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int pre = -1, ret = INT_MAX;
        DFS(root, pre, ret);
        return ret;
    }

    void DFS(TreeNode* root, int &pre, int &ret)
    {
        if (root == nullptr)
            return;

        DFS(root->left, pre, ret);
        if (pre >= 0)
            ret = min(ret, root->val - pre);
        pre = root->val;
        DFS(root->right, pre, ret);
    }
};
