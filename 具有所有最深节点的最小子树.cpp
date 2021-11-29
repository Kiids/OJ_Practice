/*
����һ����Ϊ root �Ķ�������ÿ���ڵ������� �ýڵ㵽������̾��� ��
���һ���ڵ��� ������ ������ڵ�֮�����������ȣ���ýڵ��� ����� ��
һ���ڵ�� ���� �Ǹýڵ�����������к���ļ��ϡ�
���������� �Ըýڵ�Ϊ���������а�����������Ľڵ� ��һ�����ľ��������ȵĽڵ㡣
ʾ�� 1��
���룺root = [3,5,1,6,2,0,8,null,null,7,4]
�����[2,7,4]
���ͣ�
���Ƿ���ֵΪ 2 �Ľڵ㣬��ͼ���û�ɫ��ǡ�
��ͼ������ɫ��ǵ�����������Ľڵ㡣
ע�⣬�ڵ� 5��3 �� 2 ������������Ľڵ㣬���ڵ� 2 ��������С��������Ƿ�������
ʾ�� 2��
���룺root = [1]
�����[1]
���ͣ����ڵ�����������Ľڵ㡣
ʾ�� 3��
���룺root = [0,1,3,null,2]
�����[2]
���ͣ���������Ľڵ�Ϊ 2 ����Ч����Ϊ�ڵ� 2��1 �� 0 �����������ڵ� 2 ��������С��
��ʾ��
���нڵ���������� 1 �� 500 ֮�䡣
0 <= Node.val <= 500
ÿ���ڵ��ֵ���Ƕ�һ�޶��ġ�
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
    unordered_map<TreeNode*, int> depth;
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == NULL)
            return NULL;
        int left = Depth(root->left), right = Depth(root->right);
        if (left == right)
            return root;
        if (left > right)
            return subtreeWithAllDeepest(root->left);
        return subtreeWithAllDeepest(root->right);
    }

    int Depth(TreeNode* node)
    {
        if (node == NULL)
            return 0;
        if (depth.count(node))
            return depth[node];
        return 1 + max(Depth(node->left), Depth(node->right));
    }
};
