/*
����һ�ö�����������Ҫ��������ֱ�����ȡ�һ�ö�������ֱ�������������������·�������е����ֵ������·�����ܴ���Ҳ���ܲ���������㡣
ʾ�� :
����������
          1
         / \
        2   3
       / \     
      4   5    
���� 3, ���ĳ�����·�� [4,2,1,3] ���� [5,2,1,3]��
ע�⣺�����֮���·��������������֮��ߵ���Ŀ��ʾ��
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
    int max_length = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        dfs(root);
        return max_length;
    }

    int dfs(TreeNode* root)
    {
        if (!root->left && !root->right)
            return 0;
        int left_depth = root->left == nullptr ? 0 : dfs(root->left) + 1;
        int right_depth = root->right == nullptr ? 0 : dfs(root->right) + 1;
        max_length = std::max(max_length, (left_depth + right_depth));
        return std::max(left_depth, right_depth);
    }
};
