/*
���������ݽṹTreeNode��������ʾ������������left�ÿգ�rightΪ��һ������ڵ㣩��ʵ��һ���������Ѷ���������ת��Ϊ��������Ҫ��ֵ��˳�򱣳ֲ��䣬ת������Ӧ��ԭַ�ģ�Ҳ������ԭʼ�Ķ�����������ֱ���޸ġ�
����ת����ĵ��������ͷ�ڵ㡣
ע�⣺�������ԭ�������Ķ�
ʾ����
���룺 [4,2,5,1,3,null,6,0]
����� [0,null,1,null,2,null,3,null,4,null,5,null,6]
��ʾ��
�ڵ��������ᳬ�� 100000��
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
    TreeNode* p = new TreeNode(0);
    TreeNode* ret = p;
public:
    TreeNode* convertBiNode(TreeNode* root) {
        dfs(root);
        return ret->right;
    }
    TreeNode* dfs(TreeNode* r)
    {
        if (r != nullptr)
        {
            dfs(r->left);
            r->left = nullptr;
            p->right = r;
            p = r;
            dfs(r->right);
        }
        return nullptr;
    }
};
