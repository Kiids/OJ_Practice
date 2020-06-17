/*
����һ�ö�����������ÿ���ڵ㶼����һ��������ֵ(��ֵ������)�����һ���㷨����ӡ�ڵ���ֵ�ܺ͵���ĳ������ֵ������·����������ע�⣬·����һ���ǵôӶ������ĸ��ڵ��Ҷ�ڵ㿪ʼ������������䷽���������(ֻ�ܴӸ��ڵ�ָ���ӽڵ㷽��)��
ʾ��:
�������¶��������Լ�Ŀ���?sum = 22��
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
����:
3
���ͣ���Ϊ 22 ��·���У�[5,4,11,2], [5,8,4,5], [4,11,7]
��ʾ��
�ڵ����� <= 10000
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
    int counter = 0;
    void DFS(TreeNode* root, int target)
    {
    if (root == NULL)
        return;
    target = target-root->val;
    if (target == 0)
        counter++;
    DFS(root->left,target);
    DFS(root->right,target);
    }
    void solve(TreeNode *root,int sum)
    {
        if (root == NULL)
            return;
        DFS(root,sum);
        solve(root->left, sum);
        solve(root->right, sum);
    }
    int pathSum(TreeNode* root, int sum)
    {
        solve(root, sum);
        return counter;
    }
};
