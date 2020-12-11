/*
����һ���ǿ�����Ķ�������ÿ���ڵ㶼������������ÿ���ڵ���ӽڵ�����ֻ��Ϊ 2 �� 0�����һ���ڵ��������ӽڵ�Ļ�����ô�ýڵ��ֵ���������ӽڵ��н�С��һ����
����ʽ��˵��root.val = min(root.left.val, root.right.val) �ܳ�����
����������һ��������������Ҫ������нڵ��еĵڶ�С��ֵ������ڶ�С��ֵ�����ڵĻ������ -1 ��
ʾ�� 1��
���룺root = [2,2,5,null,null,5,7]
�����5
���ͣ���С��ֵ�� 2 ���ڶ�С��ֵ�� 5 ��
ʾ�� 2��
���룺root = [2,2,2]
�����-1
���ͣ���С��ֵ�� 2, ���ǲ����ڵڶ�С��ֵ��
��ʾ��
���нڵ���Ŀ�ڷ�Χ [1, 25] ��
1 <= Node.val <= 231 - 1
��������ÿ���ڵ� root.val == min(root.left.val, root.right.val)
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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root || !root->left || !root->right)
            return -1;
        
        int l = root->left->val, r = root->right->val;
        if (root->val == root->left->val)
            l = findSecondMinimumValue(root->left);
        if (root->val == root->right->val)
            r = findSecondMinimumValue(root->right);
            
        if (root->val == l && root->val == r)
            return -1;

        int minLR = min(l, r);
        if (root->val < minLR)
            return minLR;
        else
            return max(l, r);
    }
};
