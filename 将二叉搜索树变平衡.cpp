/*
����һ�ö��������������㷵��һ�� ƽ��� �Ķ����������������ɵ���Ӧ����ԭ������������ͬ�Ľڵ�ֵ��
���һ�ö����������У�ÿ���ڵ�����������߶Ȳ���� 1 �����Ǿͳ���ö����������� ƽ��� ��
����ж��ֹ��췽�������㷵������һ�֡�
ʾ����
���룺root = [1,null,2,null,3,null,4,null,null]
�����[2,1,3,null,null,null,4]
���ͣ��ⲻ��Ψһ����ȷ�𰸣�[3,1,4,null,2,null,null] Ҳ��һ�����еĹ��췽����
��ʾ��
���ڵ����Ŀ�� 1 �� 10^4 ֮�䡣
���ڵ��ֵ������ͬ������ 1 �� 10^5 ֮�䡣
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
    void Inorder(TreeNode* root, std::vector<int>& v)
    {
        if (!root)
            return ;
        Inorder(root->left, v);
        v.push_back(root->val);
        Inorder(root->right, v);
    }

    TreeNode* constructBST(vector<int>& nums, int left, int right)
    {
        if (left > right)
            return NULL;
        TreeNode* root = new TreeNode;
        int index = left + (right - left) / 2;
        root->val = nums[index];
        root->left = constructBST(nums, left, index - 1);
        root->right = constructBST(nums, index + 1, right);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        std::vector<int> v;
        Inorder(root, v);
        return constructBST(v, 0, v.size() - 1);
    }
};
