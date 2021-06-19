/*
����һ�ø�Ϊ root �Ķ����������㷵�ض������кýڵ����Ŀ��
���ýڵ㡹X ����Ϊ���Ӹ����ýڵ� X �������Ľڵ��У�û���κνڵ��ֵ���� X ��ֵ��
ʾ�� 1��
���룺root = [3,1,4,3,null,1,5]
�����4
���ͣ�ͼ����ɫ�ڵ�Ϊ�ýڵ㡣
���ڵ� (3) ��Զ�Ǹ��ýڵ㡣
�ڵ� 4 -> (3,4) ��·���е����ֵ��
�ڵ� 5 -> (3,4,5) ��·���е����ֵ��
�ڵ� 3 -> (3,1,3) ��·���е����ֵ��
ʾ�� 2��
���룺root = [3,3,null,4,2]
�����3
���ͣ��ڵ� 2 -> (3, 3, 2) ���Ǻýڵ㣬��Ϊ "3" ������
ʾ�� 3��
���룺root = [1]
�����1
���ͣ����ڵ��Ǻýڵ㡣
��ʾ��
�������нڵ���Ŀ��Χ�� [1, 10^5] ��
ÿ���ڵ�Ȩֵ�ķ�Χ�� [-10^4, 10^4] ��
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
    int num = 0;
    int goodNodes(TreeNode* root) {
        DFS(root, INT_MIN);
        return num;
    }

    void DFS(TreeNode*root, int max)
    {
        if (root == NULL)
            return;
        if (root->val >= max)
        {
            num++;
            max = root->val;
        }
        DFS(root->left, max);
        DFS(root->right, max);
    }
};
