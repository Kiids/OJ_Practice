/*
给定两个整数数组，preorder 和 postorder ，其中 preorder 是一个具有 无重复 值的二叉树的前序遍历，postorder 是同一棵树的后序遍历，重构并返回二叉树。
如果存在多个答案，您可以返回其中 任何 一个。
示例 1：
输入：preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
输出：[1,2,3,4,5,6,7]
示例 2:
输入: preorder = [1], postorder = [1]
输出: [1]
提示：
1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
preorder 中所有值都 不同
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
postorder 中所有值都 不同
保证 preorder 和 postorder 是同一棵二叉树的前序遍历和后序遍历
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
    TreeNode* Fun(vector<int>& pre, vector<int>& post, int prestart, int preend, int poststart, int postend)
    {
        if (prestart > preend)
            return NULL;
            
        TreeNode* root = new TreeNode(pre[prestart]);
        if (prestart == preend)                              //只有一个，直接返回
            return root;
            
        int i = poststart; 
        while (i < postend && post[i] != pre[prestart + 1])  //确定分界点，左子树的根节点
            i++;

        int len = i - poststart + 1;                         //左子树长度
        root->left = Fun(pre, post, prestart + 1, prestart + len, poststart, i);
        root->right = Fun(pre, post, prestart + 1 + len, preend, i + 1, postend - 1);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return Fun(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
    }
};

//左右子树分界点:
//1.前序的第一个和后序的最后一个都是当前根节点位置;
//2.前序中，左子树的根节点是当前根节点位置+1，而在后序中，这个位置是左子树的根节点的位置
//也就是说，分界点位置是左子树根节点的位置，在后序中找到这个位置，可以算出左子树长度

