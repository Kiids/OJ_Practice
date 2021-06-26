/*
����һ���и��ڵ�Ķ��������ҵ��������Ҷ�ڵ������������ȡ�
����һ�£�
Ҷ�ڵ� �Ƕ�������û���ӽڵ�Ľڵ�
���ĸ��ڵ�� ��� Ϊ 0�����ĳһ�ڵ�����Ϊ d���������ӽڵ����Ⱦ��� d+1
������Ǽٶ� A ��һ��ڵ� S �� ����������ȣ�S �е�ÿ���ڵ㶼���� A Ϊ���ڵ�������У��� A ����ȴﵽ�������¿��ܵ����ֵ��
ʾ�� 1��
���룺root = [3,5,1,6,2,0,8,null,null,7,4]
�����[2,7,4]
���ͣ�
���Ƿ���ֵΪ 2 �Ľڵ㣬��ͼ���û�ɫ��ǡ�
��ͼ������ɫ��ǵ�����������Ľڵ㡣
ע�⣬�ڵ� 6��0 �� 8 Ҳ��Ҷ�ڵ㣬�������ǵ������ 2 �����ڵ� 7 �� 4 ������� 3 ��
ʾ�� 2��
���룺root = [1]
�����[1]
���ͣ����ڵ�����������Ľڵ㣬���������������������ȡ�
ʾ�� 3��
���룺root = [0,1,3,null,2]
�����[2]
���ͣ����������Ҷ�ڵ��� 2 ������������������Լ���
��ʾ��
��������н��� 1 �� 1000 ���ڵ㡣
����ÿ���ڵ��ֵ���� 1 �� 1000 ֮�䡣
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
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int height;
        return find(root, height);
    }

    TreeNode* find(TreeNode* root, int& height) {
        if (root == nullptr)
        {
            height = -1;
            return NULL;
        }
        int leftHeight, rightHeight;
        auto left = find(root->left, leftHeight);
        auto right = find(root->right, rightHeight);
        height = max(leftHeight, rightHeight) + 1;
        if (leftHeight == rightHeight)
            return root;
        if (leftHeight > rightHeight)
            return left;
        return right;
    }
};
