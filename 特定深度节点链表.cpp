/*
����һ�ö����������һ���㷨����������ĳһ��������нڵ���������磬��һ���������Ϊ D����ᴴ���� D ������������һ������������ȵ���������顣
ʾ����
���룺[1,2,3,4,5,null,7,8]
        1
       /  \ 
      2    3
     / \    \ 
    4   5    7
   /
  8
�����[[1],[2,3],[4,5,7],[8]]
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
