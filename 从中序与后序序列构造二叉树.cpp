/*
����һ��������������������������������
ע��:
����Լ�������û���ظ���Ԫ�ء�
���磬����
������� inorder =?[9,3,15,20,7]
������� postorder = [9,15,7,20,3]
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0 || inorder.size() == 0)
            return NULL;
        return _buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* _buildTree(vector<int>& postorder, int pbegin, int pend, vector<int>& inorder, int ibegin, int iend)
    {
        if (ibegin > iend || pbegin > pend)
            return NULL;
        
        int l = 0;
        for (int i = ibegin; i < iend; i++)
        {
            if (inorder[i] == postorder[pend])
                break;
            l++;
        }

        TreeNode* root = new TreeNode(postorder[pend]);

        root->left = _buildTree(postorder, pbegin, pbegin + l - 1, inorder, ibegin, ibegin + l - 1);
        root->right = _buildTree(postorder, pbegin + l, pend - 1, inorder, ibegin + l + 1, iend);

        return root;
    }
};
