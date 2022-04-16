/*
����һ�������������ĸ��ڵ� root ��һ��ֵ key��ɾ�������������е� key ��Ӧ�Ľڵ㣬����֤���������������ʲ��䡣���ض������������п��ܱ����£��ĸ��ڵ�����á�
һ����˵��ɾ���ڵ�ɷ�Ϊ�������裺
�����ҵ���Ҫɾ���Ľڵ㣻
����ҵ��ˣ�ɾ������
ʾ�� 1:
���룺root = [5,3,6,2,4,null,7], key = 3
�����[5,4,6,2,null,null,7]
���ͣ�������Ҫɾ���Ľڵ�ֵ�� 3���������������ҵ� 3 ����ڵ㣬Ȼ��ɾ������
һ����ȷ�Ĵ��� [5,4,6,2,null,null,7], ����ͼ��ʾ��
��һ����ȷ���� [5,2,6,null,4,null,7]��
ʾ�� 2:
����: root = [5,3,6,2,4,null,7], key = 0
���: [5,3,6,2,4,null,7]
����: ������������ֵΪ 0 �Ľڵ�
ʾ�� 3:
����: root = [], key = 0
���: []
��ʾ:
�ڵ����ķ�Χ [0, 10^4].
-10^5 <= Node.val <= 10^5
�ڵ�ֵΨһ
root �ǺϷ��Ķ���������
-10^5 <= key <= 10^5
 

���ף� Ҫ���㷨ʱ�临�Ӷ�Ϊ O(h)��h Ϊ���ĸ߶ȡ�
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        if (key > root->val)
            root->right = deleteNode(root->right, key);
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        else
        {
            if (!root->left)
                return root->right;
            if (!root->right)
                return root->left;
            TreeNode* node = root->right;  // ɾ���ڵ������ӽڵ㶼�� 
            while (node->left)             // Ѱ��ɾ���ڵ�����������ڵ�
                node = node->left;
            node->left = root->left;       // ɾ���ڵ����������Ϊ��������������ڵ��������
            root = root->right;            // ɾ���ڵ�����ӽڵ㶥����λ�ã��ڵ�ɾ��
        }
        return root;
    }
};
