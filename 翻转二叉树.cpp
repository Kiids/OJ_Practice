/*
��תһ�ö�������
ʾ����
���룺
     4
   /   \
  2     7
 / \   / \
1   3 6   9
�����
     4
   /   \
  7     2
 / \   / \
9   6 3   1
��ע:
����������ܵ� Max Howell �� ԭ���� ������ ��
�ȸ裺����90���Ĺ���ʦʹ������д�����(Homebrew)��������ȴ�޷�������ʱ�ڰװ���д����ת����������⣬��̫����ˡ�
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return root;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

// C++�����������ǰ�������
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                if (node->right) st.push(node->right);  // ��
                if (node->left) st.push(node->left);    // ��
                st.push(node);                          // ��
                st.push(NULL);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                swap(node->left, node->right);          // �ڵ㴦���߼�
            }
        }
        return root;
    }
};

// ������ȱ��� �������
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                swap(node->left, node->right); // �ڵ㴦��
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return root;
    }
};
