/*
����һ�������������� ������ ���¶� ��
һ������ �ڵ���¶� ���弴Ϊ���ýڵ��������Ľڵ�֮�ͺ��������ڵ�֮�͵� ��ľ���ֵ �����û���������Ļ����������Ľڵ�֮��Ϊ 0 ��û���������Ļ�Ҳ��һ�����ս����¶��� 0 ��
������ ���¶Ⱦ��������нڵ���¶�֮�͡�
ʾ�� 1��
���룺root = [1,2,3]
�����1
���ͣ�
�ڵ� 2 ���¶ȣ�|0-0| = 0��û���ӽڵ㣩
�ڵ� 3 ���¶ȣ�|0-0| = 0��û���ӽڵ㣩
�ڵ� 1 ���¶ȣ�|2-3| = 1���������������ӽڵ㣬���Ժ��� 2 ���������������ӽڵ㣬���Ժ��� 3 ��
�¶��ܺͣ�0 + 0 + 1 = 1
ʾ�� 2��
���룺root = [4,2,9,3,5,null,7]
�����15
���ͣ�
�ڵ� 3 ���¶ȣ�|0-0| = 0��û���ӽڵ㣩
�ڵ� 5 ���¶ȣ�|0-0| = 0��û���ӽڵ㣩
�ڵ� 7 ���¶ȣ�|0-0| = 0��û���ӽڵ㣩
�ڵ� 2 ���¶ȣ�|3-5| = 2���������������ӽڵ㣬���Ժ��� 3 ���������������ӽڵ㣬���Ժ��� 5 ��
�ڵ� 9 ���¶ȣ�|0-7| = 7��û�������������Ժ��� 0 �����������������ӽڵ㣬���Ժ��� 7 ��
�ڵ� 4 ���¶ȣ�|(3+5+2)-(9+7)| = |10-16| = 6��������ֵΪ 3��5 �� 2 ������ 10 ��������ֵΪ 9 �� 7 ������ 16 ��
�¶��ܺͣ�0 + 0 + 0 + 2 + 7 + 6 = 15
ʾ�� 3��
���룺root = [21,7,14,1,1,2,2,3,3]
�����9
��ʾ��
���нڵ���Ŀ�ķ�Χ�� [0, 104] ��
-1000 <= Node.val <= 1000
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
    int findTilt(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return abs(DFS(root->left) - DFS(root->right)) + findTilt(root->left) + findTilt(root->right);
    }

    int DFS(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        return root->val + DFS(root-<left) + DFS(root->right);
    }
};
