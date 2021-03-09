/*
给定一个二叉搜索树的根节点 root，返回树中任意两节点的差的最小值。
示例：
输入: root = [4,2,6,1,3,null,null]
输出: 1
解释:
注意，root是树节点对象(TreeNode object)，而不是数组。
给定的树 [4,2,6,1,3,null,null] 可表示为下图:
          4
        /   \
      2      6
     / \    
    1   3  
最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
注意：
二叉树的大小范围在 2 到 100。
二叉树总是有效的，每个节点的值都是整数，且不重复。
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
    int minDiffInBST(TreeNode* root) {
        int ret = INT_MAX, pre = -1;
        inOrder(root, ret, pre);
        return ret;
    }

    void inOrder(TreeNode* root, int &ret, int &pre)
    {
        if (root->left)
            inOrder(root->left, ret, pre);
        if (pre != -1)
            ret = min(ret, root->val - pre);
        pre = root->val;
        if (root->right)
            inOrder(root->right, ret, pre);
    }
};
