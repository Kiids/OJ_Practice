/*
����һ�������ظ�Ԫ�ص��������� nums ��һ���Դ�����ֱ�ӵݹ鹹���� �������� �������£�
�������ĸ������� nums �е����Ԫ�ء�
��������ͨ�������� ���ֵ��߲��� �ݹ鹹���������������
��������ͨ�������� ���ֵ�ұ߲��� �ݹ鹹���������������
�����и������� nums ������ �������� ��
ʾ�� 1��
���룺nums = [3,2,1,6,0,5]
�����[6,3,5,null,2,0,null,null,1]
���ͣ��ݹ����������ʾ��
- [3,2,1,6,0,5] �е����ֵ�� 6 ����߲����� [3,2,1] ���ұ߲����� [0,5] ��
    - [3,2,1] �е����ֵ�� 3 ����߲����� [] ���ұ߲����� [2,1] ��
        - �����飬���ӽڵ㡣
        - [2,1] �е����ֵ�� 2 ����߲����� [] ���ұ߲����� [1] ��
            - �����飬���ӽڵ㡣
            - ֻ��һ��Ԫ�أ������ӽڵ���һ��ֵΪ 1 �Ľڵ㡣
    - [0,5] �е����ֵ�� 5 ����߲����� [0] ���ұ߲����� [] ��
        - ֻ��һ��Ԫ�أ������ӽڵ���һ��ֵΪ 0 �Ľڵ㡣
        - �����飬���ӽڵ㡣
ʾ�� 2��
���룺nums = [3,2,1]
�����[3,null,2,null,1]
��ʾ��
1 <= nums.length <= 1000
0 <= nums[i] <= 1000
nums �е��������� ������ͬ
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traverse(nums, 0, nums.size());
    }

     TreeNode* traverse(vector<int>& nums, int start, int end) {
        if (start == end)
            return nullptr;
        if (start == end - 1)
            return new TreeNode(nums[start]);
        int maxIndex = start;
        for (int i = start + 1; i < end; i++)
            if (nums[i] > nums[maxIndex]) maxIndex = i;
        
        TreeNode* root = new TreeNode(nums[maxIndex]);
        root->left = traverse(nums, start, maxIndex);
        root->right = traverse(nums, maxIndex + 1, end);
        return root;
    }
};
