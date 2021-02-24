/*
���������ǰ����� preorder ��ƥ��Ķ�����������binary search tree���ĸ���㡣
(����һ�£������������Ƕ�������һ�֣���ÿ���ڵ㶼�������¹��򣬶��� node.left ���κκ����ֵ�� < node.val���� node.right ���κκ����ֵ�� > node.val�����⣬ǰ�����������ʾ�ڵ� node ��ֵ��Ȼ����� node.left�����ű��� node.right����
��Ŀ��֤�����ڸ����Ĳ��������������ҵ�����Ҫ��Ķ�����������
ʾ����
���룺[8,5,1,7,10,12]
�����[8,5,10,1,7,null,12]
��ʾ��
1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
preorder �е�ֵ������ͬ
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
    int i;
    vector<int> v;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        v = preorder;
        return DFS(INT_MIN, INT_MAX);
    }

    TreeNode* DFS(int l, int r)
    {
        if (i == v.size() || v[i] < l || v[i] > r)
            return nullptr;
        TreeNode* ret = new TreeNode(v[i++]);
        ret->left = DFS(l, ret->val);
        ret->right = DFS(ret->val, r);
        return ret;
    }
};
