/*
����һ�ö����������㷵�ز��������Ҷ�ӽڵ�ĺ͡�
ʾ����
���룺root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
�����15
��ʾ��
���нڵ���Ŀ�� 1 �� 10^4 ֮�䡣
ÿ���ڵ��ֵ�� 1 �� 100 ֮�䡣
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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ret = 0;
        while (!q.empty())
        {
            int l = q.size();
            ret = 0;
            while (l--)
            {
                TreeNode * t = q.front();
                q.pop();
                ret += t->val;
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
        }
        return ret;
    }
};
