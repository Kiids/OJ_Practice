/*
�ڶ������У����ڵ�λ����� 0 ����ÿ�����Ϊ k �Ľڵ���ӽڵ�λ����� k+1 ����
����������������ڵ������ͬ�������ڵ㲻ͬ����������һ�����ֵܽڵ㡣
���Ǹ����˾���Ψһֵ�Ķ������ĸ��ڵ� root���Լ�����������ͬ�ڵ��ֵ x �� y��
ֻ����ֵ x �� y ��Ӧ�Ľڵ������ֵܽڵ�ʱ���ŷ��� true�����򣬷��� false��
ʾ�� 1��
���룺root = [1,2,3,4], x = 4, y = 3
�����false
ʾ�� 2��
���룺root = [1,2,3,null,4,null,5], x = 5, y = 4
�����true
ʾ�� 3��
���룺root = [1,2,3,null,4], x = 2, y = 3
�����false
��ʾ��
�������Ľڵ������� 2 �� 100 ֮�䡣
ÿ���ڵ��ֵ����Ψһ�ġ���ΧΪ 1 �� 100 ��������
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
    bool isCousins(TreeNode* root, int x, int y) {
        int dx = 0;
        int dy = 0;
        TreeNode* px = NULL;
        TreeNode* py = NULL;
        dfs(root, NULL, 0, x, dx, &px);
        dfs(root, NULL, 0, y, dy, &py);
        return (dx == dy) && (px != py);
    }

    void dfs(TreeNode* root, TreeNode* p, int d, int x, int& depth, TreeNode** parent)
    {
        if (root == NULL)
            return;
        if (root->val == x)
        {
            *parent = p;
            depth = d;
            return;
        }
        dfs(root->left, root, d + 1, x, depth, parent);
        dfs(root->right, root, d + 1, x,  depth, parent);
    }
};
