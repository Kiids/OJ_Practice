/*
给定一个二叉树，在树的最后一行找到最左边的值。
示例 1:
输入:
    2
   / \
  1   3
输出:
1
示例 2:
输入:
        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7
输出:
7
注意: 您可以假设树（即给定的根节点）不为 NULL。
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ret;
        while (!q.empty())
        {
            ret = q.front()->val;
            int size = q.size();
            while (size--)
            {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }
        return ret;
    }
};
