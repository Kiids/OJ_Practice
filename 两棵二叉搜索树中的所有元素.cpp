/**
���� root1 �� root2 �����ö�����������
���㷵��һ���б����а��� ������ �е������������� ���� ����.
ʾ�� 1��
���룺root1 = [2,1,4], root2 = [1,0,3]
�����[0,1,1,2,3,4]
ʾ�� 2��
���룺root1 = [0,-10,10], root2 = [5,1,7,0,2]
�����[-10,0,0,1,2,5,7,10]
ʾ�� 3��
���룺root1 = [], root2 = [5,1,7,0,2]
�����[0,1,2,5,7]
ʾ�� 4��
���룺root1 = [0,-10,10], root2 = []
�����[-10,0,10]
ʾ�� 5��
���룺root1 = [1,null,8], root2 = [8,1]
�����[1,1,8,8]
��ʾ��
ÿ��������� 5000 ���ڵ㡣
ÿ���ڵ��ֵ�� [-10^5, 10^5] ֮�䡣
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ret;
        fun(root1, ret);
        fun(root2, ret);
        sort(ret.begin(), ret.end());
        return ret;
    }

    void fun(TreeNode* root, vector<int>& ret)
	{
    	if (root == nullptr)
            return;
    	ret.push_back(root->val);
    	fun(root->left, ret);
    	fun(root->right, ret);
	}
};
