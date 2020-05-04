/*
����һ�������������飬Ԫ�ظ�����ͬ�Ұ��������У���дһ���㷨������һ�ø߶���С�Ķ�����������
ʾ��:
������������: [-10,-3,0,5,9],
һ�����ܵĴ��ǣ�[0,-3,9,-10,null,5]�������Ա�ʾ��������߶�ƽ�������������

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
