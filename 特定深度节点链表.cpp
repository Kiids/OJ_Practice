/*
给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表（比如，若一棵树的深度为 D，则会创建出 D 个链表）。返回一个包含所有深度的链表的数组。
示例：
输入：[1,2,3,4,5,null,7,8]
        1
       /  \ 
      2    3
     / \    \ 
    4   5    7
   /
  8
输出：[[1],[2,3],[4,5,7],[8]]
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> ret;
        if (tree == nullptr)
            return ret;
        queue<TreeNode*> q;
        q.push(tree);
        while (!q.empty())
        {
            ListNode* tmp = new ListNode;
            ListNode* p = tmp;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* t = q.front();
                q.pop();
                ListNode* x = new ListNode(t->val);
                tmp->next = x;
                tmp = x;
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            ret.push_back(p->next);
        }
        return ret;
    }
};
