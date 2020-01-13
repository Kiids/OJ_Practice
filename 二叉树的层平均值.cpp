/*
����һ���ǿն�����, ����һ����ÿ��ڵ�ƽ��ֵ��ɵ�����.
ʾ�� 1:
����:
    3
   / \
  9  20
    /  \
   15   7
���: [3, 14.5, 11]
����:
��0���ƽ��ֵ�� 3,  ��1���� 14.5, ��2���� 11. ��˷��� [3, 14.5, 11].
ע�⣺
�ڵ�ֵ�ķ�Χ��32λ�з���������Χ�ڡ�
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
