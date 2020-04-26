/*
���ϵ��´�ӡ����������ÿ���ڵ㣬ͬһ��Ľڵ㰴�մ����ҵ�˳���ӡ��
����:
����������:?[3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
���أ�
[3,9,20,15,7]
��ʾ��
�ڵ����� <= 1000
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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr)
            return ret;
        
        queue<TreeNode*> q;
        TreeNode* cur = root;
        q.push(cur);
        while (!q.empty())
        {
            cur = q.front();
            ret.push_back(cur->val);
            q.pop();
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        return ret;
    }
};
