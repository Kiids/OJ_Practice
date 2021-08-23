/*
���ϴδ����һ���ֵ�֮���һȦ���ݺ�С͵�ַ�����һ���µĿ����Եĵ������������ֻ��һ����ڣ����ǳ�֮Ϊ�������� ���ˡ�����֮�⣬ÿ����������ֻ��һ��������������֮������һ�����֮�󣬴�����С͵��ʶ��������ط������з��ݵ�����������һ�ö��������� �������ֱ�������ķ�����ͬһ�����ϱ���٣����ݽ��Զ�������
�����ڲ���������������£�С͵һ���ܹ���ȡ����߽�
ʾ�� 1:
����: [3,2,3,null,3,null,1]
     3
    / \
   2   3
    \   \ 
     3   1
���: 7 
����: С͵һ���ܹ���ȡ����߽�� = 3 + 3 + 1 = 7.
ʾ�� 2:
����: [3,4,5,1,3,null,1]
     3
    / \
   4   5
  / \   \ 
 1   3   1
���: 9
����: С͵һ���ܹ���ȡ����߽�� = 4 + 5 = 9.
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
    int rob(TreeNode* root) {
        int ret = 0, pre = 0;
        fun(root, ret, pre);
        return ret;
    }

    void fun(TreeNode* node, int& ret, int& pre)
    {
        if (node == nullptr)
            return;
        int left_ret = 0, left_pre = 0, right_ret = 0, right_pre = 0;
        fun(node->left, left_ret, left_pre);
        fun(node->right, right_ret, right_pre);
        pre = left_ret + right_ret;
        ret = max(left_pre + right_pre + node->val, pre);
    }
};
