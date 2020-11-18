/*
给定一个二叉树，返回所有从根节点到叶子节点的路径。
说明: 叶子节点是指没有子节点的节点。
示例:
输入:
   1
 /   \
2     3
 \
  5
输出: ["1->2->5", "1->3"]
解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        string s;
        if (root == NULL)
            return ret;
        DFS(root, s, ret);
        return ret;
    }

    void DFS(TreeNode* cur, string path, vector<string>& v)
    {
        path += to_string(cur->val);
        if (cur->left == NULL && cur->right == NULL)
        {
            v.push_back(path);
            return;
        }
        if (cur->left)
            DFS(cur->left, path + "->", v);
        if (cur->right)
            DFS(cur->right, path + "->", v);
    }
};
