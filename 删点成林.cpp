/*
给出二叉树的根节点 root，树上每个节点都有一个不同的值。
如果节点值在 to_delete 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。
返回森林中的每棵树。你可以按任意顺序组织答案。
示例 1：
输入：root = [1,2,3,4,5,6,7], to_delete = [3,5]
输出：[[1,2,null,4],[6],[7]]
示例 2：
输入：root = [1,2,4,null,3], to_delete = [3]
输出：[[1,2,4]]
提示：
树中的节点数最大为 1000。
每个节点都有一个介于 1 到 1000 之间的值，且各不相同。
to_delete.length <= 1000
to_delete 包含一些从 1 到 1000、各不相同的值。
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s(begin(to_delete), end(to_delete));
        vector<TreeNode*> v;
        function<void(TreeNode*, TreeNode*, bool)> DFS = [&](TreeNode* t, TreeNode* rear, bool right)
        {
            if (!t)
                return ;
            if (s.count(t->val))
            {
                if (rear)
                    right ? rear->right = nullptr : rear->left = nullptr;
            }
            else if (!rear || s.count(rear->val))
                v.push_back(t);
            DFS(t->left, t, 0);
            DFS(t->right, t, 1);
        };  
        DFS(root, nullptr, 0);
        return v;
    }
};
