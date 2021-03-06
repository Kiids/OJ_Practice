/*
设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。
如果指定节点没有对应的“下一个”节点，则返回null。
示例 1:
输入: root = [2,1,3], p = 1
  2
 / \
1   3
输出: 2
示例 2:
输入: root = [5,3,6,2,4,null,null,1], p = 6
      5
     / \
    3   6
   / \
  2   4
 /   
1
输出: null
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root)
            return NULL;

        if (root->val <= p->val)
            return inorderSuccessor(root->right, p);
        else
        {
            TreeNode *leftRet = inorderSuccessor(root->left, p);
            if (!leftRet)
                return root;
            else
                return leftRet;
        }
    }
};
