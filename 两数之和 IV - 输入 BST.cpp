/*
给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
案例 1:
输入: 
    5
   / \
  3   6
 / \   \
2   4   7
Target = 9
输出: True
案例 2:
输入: 
    5
   / \
  3   6
 / \   \
2   4   7
Target = 28
输出: False
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
    vector<int> v;
    bool findTarget(TreeNode* root, int k) {
        traverse(root);
        int size = v.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = size - 1; j > i; j--)
                if (v[i] + v[j] == k)
                    return true;
        }
        return false;
    }

    void traverse(TreeNode *root)
    {
        if (root == NULL)
            return;
        traverse(root->left);
        v.push_back(root->val);
        traverse(root->right);
    }
};
