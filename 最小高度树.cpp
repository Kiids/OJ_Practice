/*
给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    TreeNode* _sortedArrayToBST(vector<int>& nums, int l, int r)
    {
        if (l > r)
            return NULL;
        int m = (l + r) / 2;
        TreeNode* node = new TreeNode(nums[m]);
        node->left = _sortedArrayToBST(nums, l, m - 1);
        node->right = _sortedArrayToBST(nums, m + 1, r);
        return node;
    }
};
