/*
����һ���������������䰴��α����Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��
����:
����������:?[3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
�������α��������
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
		int len = 1;  // ����ÿ�����
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
