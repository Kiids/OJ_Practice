/*
给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
示例：
输入：
   1
    \
     3
    /
   2
输出：
1
解释：
最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
提示：
树中至少有 2 个节点。
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
