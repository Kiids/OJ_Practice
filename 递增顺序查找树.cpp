/*
����һ���������� ��������� ������������ʹ��������ߵĽ�����������ĸ�������ÿ�����û�����ӽ�㣬ֻ��һ�����ӽ�㡣
ʾ�� ��
���룺[5,3,6,2,4,null,8,1,null,null,null,7,9]
       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9
�����[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9  
��ʾ��
�������еĽ�������� 1 �� 100 ֮�䡣
ÿ����㶼��һ���� 0 �� 1000 ��Χ�ڵ�Ψһ����ֵ��
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
    void inOrder(TreeNode* root, vector<int> &ret)
    {
        if (root == NULL)
            return;
        inOrder(root->left, ret);
        ret.push_back(root->val);
        inOrder(root->right, ret);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        inOrder(root, v);
        TreeNode *ret = new TreeNode(0), *cur = ret;
        for (auto i : v)
        {
            cur->right = new TreeNode(i);
            cur = cur->right;
        }
        return ret->right;
    }
};
