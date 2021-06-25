/*
��������������� root ����������ÿ������ֵҪô�� 0��Ҫô�� 1��
�����Ƴ������в����� 1 ��������ԭ��������
( �ڵ� X ������Ϊ X �����Լ����� X �ĺ����)
ʾ��1:
����: [1,null,0,0,1]
���: [1,null,0,null,1]
����: 
ֻ�к�ɫ�ڵ��������������в����� 1 ����������
��ͼΪ���صĴ𰸡�
ʾ��2:
����: [1,0,1,0,0,0,1]
���: [1,null,1,null,1]
ʾ��3:
����: [1,1,0,1,1,0,1,0]
���: [1,1,0,1,1,null,1]
˵��:
�����Ķ���������� 100 ���ڵ㡣
ÿ���ڵ��ֵֻ��Ϊ 0 �� 1 ��
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
    TreeNode* pruneTree(TreeNode* root) {
        return DFS(root) ? root : nullptr;
    }

    bool DFS(TreeNode* node)
    {
        if (node !=  nullptr)
        {
            bool left = node->left ? DFS(node->left) : false;
            bool right = node->right ? DFS(node->right) : false;
            if (!left)
                node->left = nullptr;
            if (!right)
                node->right = nullptr;
            return node->val == 1 || left || right;
        }
        else
            return false;
    }
};
