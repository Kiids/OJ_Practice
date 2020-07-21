/*
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
示例:
给定有序数组: [-10,-3,0,5,9],
一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
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
    //构建nums下标为l-r
    TreeNode* buildTree(vector<int>& nums, int l, int r)
    {
        if (l > r)
            return nullptr;  //没有元素
        int mid = (l + r) >> 1;  //根节点的值
        TreeNode* root = new TreeNode(nums[mid]);
        //与归并类似 递归构建左右节点
        root->left = buildTree(nums, l, mid - 1);  //递归左节点
        root->right = buildTree(nums, mid + 1, r);  //递归右节点
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return buildTree(nums, 0, nums.size() - 1);
    }
};
