/*
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
叶子节点 是指没有子节点的节点。
示例 1：
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]
示例 2：
输入：root = [1,2,3], targetSum = 5
输出：[]
示例 3：
输入：root = [1,2], targetSum = 0
输出：[]
提示：
树中节点总数在范围 [0, 5000] 内
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
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
    vector<vector<int>> v;
    vector<int> path;
public:
    void preorder(TreeNode* node, int path_value, int sum, vector<int>& path, vector<vector<int>>& v)
    {
        if (!node)  
            return ;
        path_value += node->val;
        path.push_back(node->val);
        if (!node->left && !node->right && path_value == sum)
            v.push_back(path);
        preorder(node->left, path_value, sum, path, v);
        preorder(node->right, path_value, sum, path, v);
        path_value -= node->val;
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        preorder(root, 0, targetSum, path, v);
        return v;
    }
};
