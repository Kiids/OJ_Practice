/*
给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。
进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？
示例 1：
输入：root = [1,3,null,null,2]
输出：[3,1,null,null,2]
解释：3 不能是 1 左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
示例 2：
输入：root = [3,1,4,null,null,2]
输出：[2,1,4,null,null,3]
解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。
提示：
树上节点的数目在范围 [2, 1000] 内
-2^31 <= Node.val <= 2^31 - 1
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
    void recoverTree(TreeNode* root) {
        TreeNode* predecessor=nullptr,* pre=nullptr;
        TreeNode* former=nullptr,* later=nullptr;
        while (root)
        {
            if (root->left)
            {
                predecessor=root->left;
                while (predecessor->right && predecessor->right != root)
                    predecessor = predecessor->right;
                if (predecessor->right)
                    predecessor->right = nullptr;
                else
                {
                    predecessor->right = root;
                    root = root->left;
                    continue;
                }
            }
            if (pre && pre->val>root->val)
            {
                later = root;
                if (!former)
                    former = pre;
            }
            pre = root;
            root = root->right;
        }
        swap(former->val, later->val);
        return;
    }
};
