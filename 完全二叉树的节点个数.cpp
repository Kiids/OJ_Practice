/*
����һ�� ��ȫ������ �ĸ��ڵ� root ����������Ľڵ������
��ȫ������ �Ķ������£�����ȫ�������У�������ײ�ڵ����û�����⣬����ÿ��ڵ������ﵽ���ֵ������������һ��Ľڵ㶼�����ڸò�����ߵ�����λ�á�����ײ�Ϊ�� h �㣬��ò���� 1~ 2h ���ڵ㡣
ʾ�� 1��
���룺root = [1,2,3,4,5,6]
�����6
ʾ�� 2��
���룺root = []
�����0
ʾ�� 3��
���룺root = [1]
�����1
��ʾ��
���нڵ����Ŀ��Χ��[0, 5 * 104]
0 <= Node.val <= 5 * 104
��Ŀ���ݱ�֤��������� ��ȫ������
���ף���������ͳ�ƽڵ���һ��ʱ�临�Ӷ�Ϊ O(n) �ļ򵥽����������������һ��������㷨��
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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        TreeNode *left = root->left, *right = root->right;
        int l_height = getHeight(left);   // �������߶� 
        int r_height = getHeight(right);  // �������߶� 
        if (l_height == r_height)         // ���������߶����ʱ����������Ϊ�������� 
            return (1 << l_height) + countNodes(right);
        else                              // �����ʱ����������Ϊ������������Ϊ�������ĵ����ڶ��������ģ� 
            return (1 << r_height) + countNodes(left);
    }

    int getHeight(TreeNode* root)
    {
        if (!root)
            return 0;
        int height = 1;
        while (root->left)
        {
            root = root->left;
            height++;
        }
        return height;
    }
};
