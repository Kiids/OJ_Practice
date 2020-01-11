/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
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
  [9,20],
  [15,7]
]
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
		if (root == NULL)
			return ret;

		vector<int> v;
        
		queue<TreeNode*> q;
		TreeNode* cur = root;
		q.push(cur);
		int len = 1;  // 控制每层个数
		while (!q.empty())
		{
			for (int i = 0; i < len; ++i)
			{
				cur = q.front();
				v.push_back(cur->val);
				q.pop();
				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
			}
			ret.push_back(v);
			v.clear();
			len = q.size();
		}
		return ret;
    }
};
