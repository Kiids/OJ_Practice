/*
二叉树数据结构TreeNode可用来表示单向链表（其中left置空，right为下一个链表节点）。实现一个方法，把二叉搜索树转换为单向链表，要求值的顺序保持不变，转换操作应是原址的，也就是在原始的二叉搜索树上直接修改。
返回转换后的单向链表的头节点。
注意：本题相对原题稍作改动
示例：
输入： [4,2,5,1,3,null,6,0]
输出： [0,null,1,null,2,null,3,null,4,null,5,null,6]
提示：
节点数量不会超过 100000。
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
    TreeNode* p = new TreeNode(0);
    TreeNode* ret = p;
public:
    TreeNode* convertBiNode(TreeNode* root) {
        dfs(root);
        return ret->right;
    }
    TreeNode* dfs(TreeNode* r)
    {
        if (r != nullptr)
        {
            dfs(r->left);
            r->left = nullptr;
            p->right = r;
            p = r;
            dfs(r->right);
        }
        return nullptr;
    }
};
