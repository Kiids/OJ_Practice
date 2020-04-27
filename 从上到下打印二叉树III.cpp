/*
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
例如:
给定二叉树:?[3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：
[
  [3],
  [20,9],
  [15,7]
]
提示：
节点总数 <= 1000
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q;

        if(root==NULL)
            return ret;
        
        int deep;
        q.push(root);
        deep = 1;

        vector<int> v;
        while (!q.empty())
        {
            int size = q.size();
            v.clear();
            while (size--)
            {
                TreeNode* front = q.front();
                q.pop();

                if (front->left)
                    q.push(front->left);

                if (front->right)
                    q.push(front->right);

                v.push_back(front->val);
            }
            
            if ((deep++) % 2 == 0)
                reverse(v.begin(), v.end());
                
            ret.push_back(v);
        }
        return ret;
    }
};
