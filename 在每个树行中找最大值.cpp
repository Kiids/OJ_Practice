/*
您需要在二叉树的每一行中找到最大的值。
示例：
输入: 
          1
         / \
        3   2
       / \   \  
      5   3   9 
输出: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> ret;
        vector<int> ret2;
		if (root == NULL)
			return ret2;

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

		for (int i = 0; i < ret.size(); i++)
        {
            int max = INT_MIN;;
            for (int j = 0; j < ret[i].size(); j++)
            {
                if (ret[i][j] > max)
                    max = ret[i][j];
            }
            ret2.push_back(max);
        }
        return ret2;
    }
};
