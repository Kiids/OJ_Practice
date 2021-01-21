/*
�������� ���� ���ĸ��ڵ㣬�����Ľڵ�ֵ������ͬ�����㽫��ת��Ϊ�ۼ�����Greater Sum Tree����ʹÿ���ڵ� node ����ֵ����ԭ���д��ڻ���� node.val ��ֵ֮�͡�
����һ�£�������������������Լ��������
�ڵ���������������� С�� �ڵ���Ľڵ㡣
�ڵ���������������� ���� �ڵ���Ľڵ㡣
��������Ҳ�����Ƕ�����������
ʾ�� 1��
���룺[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
�����[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
ʾ�� 2��
���룺root = [0,null,1]
�����[1,null,1]
ʾ�� 3��
���룺root = [1,0,2]
�����[3,3,2]
ʾ�� 4��
���룺root = [3,2,4,1]
�����[7,9,4,10]
��ʾ��
���еĽڵ������� 1 �� 100 ֮�䡣
ÿ���ڵ��ֵ���� 0 �� 100 ֮�䡣
���е�����ֵ ������ͬ ��
��������Ϊ������������
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
    TreeNode* bstToGst(TreeNode* root) {
        DFS(root, 0);
        return root;
    }

    int DFS(TreeNode* root, int add)
    {
        if (root == nullptr)
            return add;
        root->val += DFS(root->right, add);
        return DFS(root->left, root->val);
    }
};
