/*
����һ�ö�����������ÿ������ֵ���� 0 �� 1 ��ÿһ���Ӹ���Ҷ��·��������һ���������Чλ��ʼ�Ķ������������磬���·��Ϊ 0 -> 1 -> 1 -> 0 -> 1����ô����ʾ�������� 01101��Ҳ���� 13 ��
�����ϵ�ÿһƬҶ�ӣ����Ƕ�Ҫ�ҳ��Ӹ�����Ҷ�ӵ�·������ʾ�����֡�
�� 10^9 + 7 Ϊģ��������Щ����֮�͡�
ʾ����
���룺[1,0,1,0,1,0,1]
�����22
���ͣ�(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
��ʾ��
���еĽ�������� 1 �� 1000 ֮�䡣
node.val Ϊ 0 �� 1 ��
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
    int sumRootToLeaf(TreeNode* root) {
        return _sumRootToLeaf(root, 0);
    }
    
    int _sumRootToLeaf(TreeNode* root, int n)
    {
        if (root == NULL)
            return 0;
        
        n = n << 1;
        n += root->val;
        
        if (root->left == NULL && root->right == NULL)
            return n;
        
        return _sumRootToLeaf(root->left, n) + _sumRootToLeaf(root->right, n);
    }
};
