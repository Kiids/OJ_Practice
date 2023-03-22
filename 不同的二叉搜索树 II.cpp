/*
给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
示例 1：
输入：n = 3
输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
示例 2：
输入：n = 1
输出：[[1]]
提示：
1 <= n <= 8
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};
        return fun(1, n);
    }

    vector<TreeNode*> fun(int st, int n)
    {
        vector<TreeNode*> v;
        if (st > n)
            return {NULL};
        for (int i = st; i <= n; i++)
        {
            for (auto& l : fun(st, i - 1))
            {
                for (auto& r : fun(i + 1, n))
                {
                    TreeNode* root = new TreeNode(i, l, r);
                    v.push_back(root);
                }
            }            
        }
        return v;
    }
};

// 递归 
