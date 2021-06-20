/*
����һ���� N �����Ķ������ĸ���� root�����е�ÿ������϶���Ӧ�� node.val öӲ�ң������ܹ��� N öӲ�ҡ�
��һ���ƶ��У����ǿ���ѡ���������ڵĽ�㣬Ȼ��һöӲ�Ҵ�����һ������ƶ�����һ����㡣(�ƶ������ǴӸ���㵽�ӽ�㣬���ߴ��ӽ���ƶ�������㡣)��
����ʹÿ�������ֻ��һöӲ��������ƶ�������
ʾ�� 1��
���룺[3,0,0]
�����2
���ͣ������ĸ���㿪ʼ�����ǽ�һöӲ���Ƶ��������ӽ���ϣ�һöӲ���Ƶ��������ӽ���ϡ�
ʾ�� 2��
���룺[0,3,0]
�����3
���ͣ��Ӹ��������ӽ�㿪ʼ�����ǽ���öӲ���Ƶ�������� [�ƶ�����]��Ȼ�����ǰ�һöӲ�ҴӸ�����Ƶ����ӽ���ϡ�
ʾ�� 3��
���룺[1,0,2]
�����2
ʾ�� 4��
���룺[1,0,0,null,3]
�����4
��ʾ��
1<= N <= 100
0 <= node.val <= N
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
    int distributeCoins(TreeNode* root) {
        int ret = 0;
        DFS(root, ret);
        return ret;
    }

    int DFS(TreeNode* root, int& ret)
    {
        if (root == nullptr)
            return 0;
        int left = DFS(root->left, ret);
        int right = DFS(root->right, ret);
        ret += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
};
