/*
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
示例:
输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode*> q;
        if (root == NULL)
            return ret;
        q.push(root);
        while (!q.empty())
        {
            queue<TreeNode*> q2;
            ret.push_back(q.back()->val);
            while (!q.empty())
            {
                TreeNode* t = q.front();
                q.pop();
                if (t->left)
                    q2.push(t->left);
                if (t->right)
                    q2.push(t->right);
            }
            q = q2;
        }
        return ret;
    }
};
