/*
给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.
示例 1:
输入:
    3
   / \
  9  20
    /  \
   15   7
输出: [3, 14.5, 11]
解释:
第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
注意：
节点值的范围在32位有符号整数范围内。
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> ret;
        vector<double> ret2;
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
            double sum = 0;
            for (int j = 0; j < ret[i].size(); j++)
            {
                sum += ret[i][j];
            }
            ret2.push_back((double)sum / ret[i].size());
        }
        return ret2;
    }
};
