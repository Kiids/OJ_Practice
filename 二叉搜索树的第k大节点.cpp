/*
����һ�ö��������������ҳ����е�k��Ľڵ㡣
ʾ�� 1:
����: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
���: 4
ʾ�� 2:
����: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
���: 4
���ƣ�
1 �� k �� ����������Ԫ�ظ���
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
    int kthLargest(TreeNode* root, int k) {
        vector<int> v = getK(root);
        return v[v.size() - k];
    }
    vector<int> ret;
    vector<int> getK(TreeNode* root)
    {
        if (root == nullptr)
            return ret;
        if (root->left != nullptr)
            getK(root->left);
        ret.push_back(root->val);
        if (root->right != nullptr)
            getK(root->right);
        return ret;
    }
};
