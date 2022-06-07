/*
����һ�ö������ĸ� root�����㿼�������� �Ӹ���Ҷ��·�����Ӹ����κ�Ҷ��·��������νһ��Ҷ�ӽڵ㣬����һ��û���ӽڵ�Ľڵ㣩
����ͨ���ڵ� node ��ÿ�ֿ��ܵ� ����-Ҷ�� ·����ֵ���ܺ�ȫ��С�ڸ����� limit����ýڵ㱻��֮Ϊ������ڵ㡹����Ҫ��ɾ����
����ɾ�����в���ڵ㣬���������ɵĶ������ĸ���
ʾ�� 1��
���룺root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
�����[1,2,3,4,null,null,7,8,9,null,14]
ʾ�� 2��
���룺root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
�����[5,4,8,11,null,17,4,7,null,null,null,5]
ʾ�� 3��
���룺root = [5,-6,-6], limit = 0
�����[]
��ʾ��
���������� 1 �� 5000 ���ڵ�
-10^5 <= node.val <= 10^5
-10^9 <= limit <= 10^9
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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (!root)
            return root;
        if (!root->left && !root->right)
        {
            if (root->val >= limit)
                return root;
            else
                return nullptr;
        }
        root->left = sufficientSubset(root->left, limit - root->val);
        root->right = sufficientSubset(root->right, limit - root->val);
        if (!root->left && !root->right)
            return nullptr;
        else
            return root;
    }
};
