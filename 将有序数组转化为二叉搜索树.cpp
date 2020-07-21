/*
��һ�������������е��������飬ת��Ϊһ�ø߶�ƽ�������������
�����У�һ���߶�ƽ���������ָһ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1��
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
    //����nums�±�Ϊl-r
    TreeNode* buildTree(vector<int>& nums, int l, int r)
    {
        if (l > r)
            return nullptr;  //û��Ԫ��
        int mid = (l + r) >> 1;  //���ڵ��ֵ
        TreeNode* root = new TreeNode(nums[mid]);
        //��鲢���� �ݹ鹹�����ҽڵ�
        root->left = buildTree(nums, l, mid - 1);  //�ݹ���ڵ�
        root->right = buildTree(nums, mid + 1, r);  //�ݹ��ҽڵ�
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return buildTree(nums, 0, nums.size() - 1);
    }
};
