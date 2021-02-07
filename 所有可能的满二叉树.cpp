/*
����������һ�������������ÿ�����ǡ���� 0 �� 2 ���ӽ�㡣
���ذ��� N ���������п��������������б� �𰸵�ÿ��Ԫ�ض���һ���������ĸ���㡣
����ÿ������ÿ����㶼������ node.val=0��
����԰��κ�˳�򷵻����������б�
ʾ����
���룺7
�����[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
���ͣ�
��ʾ��
1 <= N <= 20
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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> dp;
        // �߽�����1:����������ż����returnһ�����б�
        if (N & 1 == 0)
            return dp;
        // �߽�����2:�������Ϊ1����ô�����ֻ��һ��ֵΪ0�Ľ��
        if (N == 1)
        {
            dp.push_back(new TreeNode(0));
            return dp;
        }

        // һ����N����㣬rootռ��1����㣬������������1��3��5��..��N-2�����
        // ������������N-2��..��5��3��1�����
        // ��һ��ѭ�����ҵ����п��ܵ����������Ŀ��ܵ��������������root�Ž��б���
        for (int i = 1; i <= N - 2; i += 2)
        {
            // allPossibleFBT(i)������һ���б�������ŵ������Ϊiʱ��������������������root�ļ���
            // allPossibleFBT(i)��������������������������ļ���
            // allPossibleFBT(N-1-i)��������������������������ļ���
            // ��vector<TreeNode*> allPossibleFBT(int N)��������Ķ�����ȷ����
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(N - 1 - i);

            // ����������������ϣ���������Ϊmʱ��������������right.size()������
            // һ����right.size() * left.size()�ֿ���
            for (int j = 0; j < left.size(); j++)
            {
                for (int k = 0; k < right.size(); k++)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = left[j];
                    root->right = right[k];
                    // ������������i����㣬��������N-1-i�����ʱ�������п��ܵ���push�������
                    dp.push_back(root);
                }
            }
        }
        return dp;
    }
};
