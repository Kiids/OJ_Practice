/*
����������ĸ���� root �����㽫��չ��Ϊһ��������
չ����ĵ�����Ӧ��ͬ��ʹ�� TreeNode ������ right ��ָ��ָ����������һ����㣬������ָ��ʼ��Ϊ null ��
չ����ĵ�����Ӧ��������� ������� ˳����ͬ��
ʾ�� 1��
���룺root = [1,2,5,3,4,null,6]
�����[1,null,2,null,3,null,4,null,5,null,6]
ʾ�� 2��
���룺root = []
�����[]
ʾ�� 3��
���룺root = [0]
�����[0]
��ʾ��
���н�����ڷ�Χ [0, 2000] ��
-100 <= Node.val <= 100
���ף������ʹ��ԭ���㷨��O(1) ����ռ䣩չ���������
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
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* temp = root->right;
        root->right = root->left;
        TreeNode* foot = root;
        while (foot->right)
            foot = foot->right;
        foot->right = temp;
        root->left = NULL;
    }
};
