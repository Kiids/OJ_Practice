/*
����һ�������������������һ���ҵ�����ߵ�ֵ��
ʾ�� 1:
����:
    2
   / \
  1   3
���:
1
ʾ�� 2:
����:
        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7
���:
7
ע��: �����Լ��������������ĸ��ڵ㣩��Ϊ NULL��
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ret;
        while (!q.empty())
        {
            ret = q.front()->val;
            int size = q.size();
            while (size--)
            {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }
        return ret;
    }
};
