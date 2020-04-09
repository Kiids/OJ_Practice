/*
����һ������ǰ�������������������������
ע��:
����Լ�������û���ظ���Ԫ�ء�
���磬����
ǰ����� preorder =?[3,9,20,15,7]
������� inorder = [9,3,15,20,7]
�������µĶ�������
    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0)
            return NULL;
        return _buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* _buildTree(vector<int>& preorder, int pbegin, int pend, vector<int>& inorder, int ibegin, int iend)
    {
        TreeNode* root = new TreeNode(preorder[pbegin]);
        root->left = NULL;
        root->right = NULL;
        
        // �����Ҹ��ڵ�
        int i = ibegin;
        while (i <= iend && preorder[pbegin] != inorder[i])
            i++;
        
        int ll = i - ibegin;  // ����������
        int rl = iend- i;  // ����������
        
        if (ll > 0)
            root->left = _buildTree(preorder, pbegin + 1, pbegin + ll, inorder, ibegin, ibegin + ll - 1);
        
        if (rl > 0)
            root->right = _buildTree(preorder, pbegin + ll + 1, pend, inorder, ibegin + ll + 1, iend);
        
        return root;
    }
};
