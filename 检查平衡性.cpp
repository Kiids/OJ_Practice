/*
ʵ��һ�����������������Ƿ�ƽ�⡣����������У�ƽ�����Ķ������£�����һ���ڵ㣬�����������ĸ߶Ȳ���� 1��
ʾ�� 1:
���������� [3,9,20,null,null,15,7]
    3
   / \
  9  20
    /  \
   15   7
���� true ��
ʾ�� 2:
���������� [1,2,2,3,3,null,null,4,4]
      1
     / \
    2   2
   / \
  3   3
 / \
4   4
���� false ��
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        return abs(depth(root->left) - depth(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }
    int depth(TreeNode* r)
    {
        if (r == nullptr)
            return 0;
        return max(depth(r->left), depth(r->right)) + 1;
    }
};
