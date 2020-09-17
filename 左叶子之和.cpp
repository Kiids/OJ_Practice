/*
���������������������Ҷ��֮�͡�
ʾ����
    3
   / \
  9  20
    /  \
   15   7
������������У���������Ҷ�ӣ��ֱ��� 9 �� 15�����Է��� 24
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int ret=0;
        if (root->left != nullptr)
            if (root->left->left == nullptr && root->left->right == nullptr)
                ret += root->left->val;
            else
                ret += sumOfLeftLeaves(root->left);
        
        if (root->right != nullptr)
            ret += sumOfLeftLeaves(root->right);
        
        return ret;
    }
};
