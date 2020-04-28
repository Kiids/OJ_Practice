/*
输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
示例:
给定如下二叉树，以及目标和?sum = 22，
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:
[
   [5,4,11,2],
   [5,8,4,5]
]
提示：
节点总数 <= 10000
*/

// 回溯 
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;

        vector<int> path;
        dfs(root, ret, path, sum, 0);
        return ret;
    }
    // 前序遍历
    void dfs(TreeNode* root, vector<vector<int>>& ret, vector<int>& path, int sum, int cursum)
    {
        cursum += root->val;
        path.push_back(root->val);
        if (cursum == sum && root->left == nullptr && root->right == nullptr)
            ret.push_back(path);
        if (root->left)
            dfs(root->left, ret, path, sum, cursum);
        if (root->right)
            dfs(root->right, ret, path, sum, cursum);
        path.pop_back();
    }
};
