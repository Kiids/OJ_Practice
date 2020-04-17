/*
�����һ������������һ�����������ú���������ľ���
�������룺
     4
   /   \
  2     7
 / \   / \
1   3 6   9
���������
     4
   /   \
  7     2
 / \   / \
9   6 3   1
ʾ�� 1��
���룺root = [4,2,7,1,3,6,9]
�����[4,7,2,9,6,3,1]
���ƣ�
0 <= �ڵ���� <= 1000
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
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        swap(root->left, root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};
