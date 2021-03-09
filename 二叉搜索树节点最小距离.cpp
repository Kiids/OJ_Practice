/*
����һ�������������ĸ��ڵ� root�����������������ڵ�Ĳ����Сֵ��
ʾ����
����: root = [4,2,6,1,3,null,null]
���: 1
����:
ע�⣬root�����ڵ����(TreeNode object)�����������顣
�������� [4,2,6,1,3,null,null] �ɱ�ʾΪ��ͼ:
          4
        /   \
      2      6
     / \    
    1   3  
��С�Ĳ�ֵ�� 1, ���ǽڵ�1�ͽڵ�2�Ĳ�ֵ, Ҳ�ǽڵ�3�ͽڵ�2�Ĳ�ֵ��
ע�⣺
�������Ĵ�С��Χ�� 2 �� 100��
������������Ч�ģ�ÿ���ڵ��ֵ�����������Ҳ��ظ���
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
    int minDiffInBST(TreeNode* root) {
        int ret = INT_MAX, pre = -1;
        inOrder(root, ret, pre);
        return ret;
    }

    void inOrder(TreeNode* root, int &ret, int &pre)
    {
        if (root->left)
            inOrder(root->left, ret, pre);
        if (pre != -1)
            ret = min(ret, root->val - pre);
        pre = root->val;
        if (root->right)
            inOrder(root->right, ret, pre);
    }
};
