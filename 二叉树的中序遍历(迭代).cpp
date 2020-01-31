/*
����һ���������������������� ������
ʾ��:

����: [1,null,2,3]
   1
    \
     2
    /
   3

���: [1,3,2]
����: ͨ�������㷨
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (p != NULL || !s.empty())
        {
            while (p != NULL)
            {
                s.push(p);
                p = p->left;
            }
            if (!s.empty())
            {
                p = s.top();
                ret.push_back(p->val);
                s.pop();
                p = p->right;
            }
        }
        return ret;
    }
};

