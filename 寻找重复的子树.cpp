/*
给定一棵二叉树 root，返回所有重复的子树。
对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
如果两棵树具有相同的结构和相同的结点值，则它们是重复的。
示例 1：
输入：root = [1,2,3,4,null,2,4,null,null,4]
输出：[[2,4],[4]]
示例 2：
输入：root = [2,1,1]
输出：[[1]]
示例 3：
输入：root = [2,2,2,3,null,3,null]
输出：[[2,3],[3]]
提示：
树中的结点数在[1,10^4]范围内。
-200 <= Node.val <= 200
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
    vector<TreeNode*> v;
    unordered_map<string, int> m;
    string DFS(TreeNode* root)
    {
        if (!root)
            return "#";
        string s = to_string(root->val) + "-" + DFS(root->left) + "-" + DFS(root->right);
        m[s]++;
        if (m.count(s) == 1 && m[s] == 2)
            v.push_back(root);
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        std::cout << DFS(root) << std::endl;
        return v;
    }
};

//二叉树序列化存储在哈希表，统计每棵子树对应序列出现的次数

