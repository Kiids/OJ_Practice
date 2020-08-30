/*
���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������
ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��
ʾ�� 1��
���룺[1,1,1,1,1,null,1]
�����true
ʾ�� 2��
���룺[2,2,2,5,2]
�����false
��ʾ��
�������Ľڵ�����Χ�� [1, 100]��
ÿ���ڵ��ֵ������������ΧΪ [0, 99] ��
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
    bool isUnivalTree(TreeNode* root) {
        return isUnivalTree(root, root->val);
    }
    bool isUnivalTree(TreeNode* root, int val) {
        if (!root)
            return 1;
        if (root->val != val)
            return 0;
        return isUnivalTree(root->left, root->val) && isUnivalTree(root->right, root->val);
    }
};
