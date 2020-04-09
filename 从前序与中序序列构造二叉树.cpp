/*
根据一棵树的前序遍历与中序遍历构造二叉树。
注意:
你可以假设树中没有重复的元素。
例如，给出
前序遍历 preorder =?[3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：
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
        
        // 中序找根节点
        int i = ibegin;
        while (i <= iend && preorder[pbegin] != inorder[i])
            i++;
        
        int ll = i - ibegin;  // 左子树长度
        int rl = iend- i;  // 右子树长度
        
        if (ll > 0)
            root->left = _buildTree(preorder, pbegin + 1, pbegin + ll, inorder, ibegin, ibegin + ll - 1);
        
        if (rl > 0)
            root->right = _buildTree(preorder, pbegin + ll + 1, pend, inorder, ibegin + ll + 1, iend);
        
        return root;
    }
};
