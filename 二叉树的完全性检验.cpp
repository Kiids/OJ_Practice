/*
����һ���������� root ��ȷ�����Ƿ���һ�� ��ȫ������ ��
��һ�� ��ȫ������ �У��������һ���ؿ��⣬���йؿ�������ȫ�������ģ��������һ���ؿ��е����нڵ㶼�Ǿ����ܿ���ġ������԰��� 1 �� 2h �ڵ�֮������һ�� h ��
ʾ�� 1��
���룺root = [1,2,3,4,5,6]
�����true
���ͣ����һ��ǰ��ÿһ�㶼�����ģ��������ֵΪ {1} �� {2,3} �����㣩�������һ���е����н�㣨{4,5,6}���������ܵ�����
ʾ�� 2��
���룺root = [1,2,3,4,5,null,7]
�����false
���ͣ�ֵΪ 7 �Ľ��û�о����ܿ�����ࡣ
��ʾ��
���Ľ�����ڷ�Χ  [1, 100] �ڡ�
1 <= Node.val <= 1000
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
		q.push(root);
		bool flag = false;
		while (!q.empty())
        {
			auto x = q.front();
			q.pop();
			if (x == nullptr)
            {
				flag = true;
				continue;
			}
			if (flag)
                return false;
			q.push(x->left);
			q.push(x->right);
		}
		return true;
    }
};
