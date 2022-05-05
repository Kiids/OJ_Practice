/*
����һ���������ĸ� root ���������� val �� depth ���ڸ�������� depth �����һ��ֵΪ val �Ľڵ��С�
ע�⣬���ڵ� root λ����� 1 ��
�ӷ���������:
�������� depth���������Ϊ depth - 1 ��ÿ���ǿ����ڵ� cur ����������ֵΪ val �����ڵ���Ϊ cur ����������������������
cur ԭ����������Ӧ�����µ�������������������
cur ԭ����������Ӧ�����µ�������������������
��� depth == 1 ��ζ�� depth - 1 ����û����ȣ���ô����һ�����ڵ㣬ֵ val ��Ϊ����ԭʼ�����¸�����ԭʼ�������¸�����������
ʾ�� 1:
����: root = [4,2,6,3,1,5], val = 1, depth = 2
���: [4,1,1,2,null,null,6,3,1,5]
ʾ�� 2:
����: root = [4,2,null,3,1], val = 1, depth = 3
���:  [4,2,null,1,1,3,null,null,1]
��ʾ:
�ڵ����� [1, 10^4] ��Χ��
��������� [1, 10^4]��Χ��
-100 <= Node.val <= 100
-10^5 <= val <= 10^5
1 <= depth <= the depth of tree + 1
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
    void preorder(TreeNode* root, int hight, int depth, int val)
    {
        if (!root)
            return;

        if (hight == depth - 1)
        {
            TreeNode* temp = root->left;
            root->left = new TreeNode(val);
            root->left->left = temp;

            temp = root->right;
            root->right = new TreeNode(val);
            root->right->right = temp;

        }
        preorder(root->left, hight + 1, depth, val);
        preorder(root->right, hight + 1, depth, val);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth ==1)
        {
            // ��v����ȥ
            TreeNode* root1 = new TreeNode(val);
            root1->left = root;
            return root1;           
        }
        preorder(root, 1, depth, val);
        return root;
    }
};
