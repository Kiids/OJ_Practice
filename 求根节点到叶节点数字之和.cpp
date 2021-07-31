/*
����һ���������ĸ��ڵ� root ������ÿ���ڵ㶼�����һ�� 0 �� 9 ֮������֡�
ÿ���Ӹ��ڵ㵽Ҷ�ڵ��·��������һ�����֣�
���磬�Ӹ��ڵ㵽Ҷ�ڵ��·�� 1 -> 2 -> 3 ��ʾ���� 123 ��
����Ӹ��ڵ㵽Ҷ�ڵ����ɵ� ��������֮�� ��
Ҷ�ڵ� ��ָû���ӽڵ�Ľڵ㡣
ʾ�� 1��
���룺root = [1,2,3]
�����25
���ͣ�
�Ӹ���Ҷ�ӽڵ�·�� 1->2 �������� 12
�Ӹ���Ҷ�ӽڵ�·�� 1->3 �������� 13
��ˣ������ܺ� = 12 + 13 = 25
ʾ�� 2��
���룺root = [4,9,0,5,1]
�����1026
���ͣ�
�Ӹ���Ҷ�ӽڵ�·�� 4->9->5 �������� 495
�Ӹ���Ҷ�ӽڵ�·�� 4->9->1 �������� 491
�Ӹ���Ҷ�ӽڵ�·�� 4->0 �������� 40
��ˣ������ܺ� = 495 + 491 + 40 = 1026
��ʾ��
���нڵ����Ŀ�ڷ�Χ [1, 1000] ��
0 <= Node.val <= 9
������Ȳ����� 10
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
    int sumNumbers(TreeNode* root) {
        int ret = 0;
        vector<int> v;
        if (root == nullptr)
            return 0;
        v = getnumber(root, ret ,v);
        for (auto i : v)
            ret += i;
        return ret;
    }

    vector<int> getnumber(TreeNode* root, int sum, vector<int>& v)
    {
        sum = 10 * sum + root->val;
        if (!root->left && !root->right)
        {
            v.push_back(sum);
            return v;
        }
        if (root->left)
            getnumber(root->left, sum, v);
        if (root->right)
            getnumber(root->right, sum, v);
        return v;
    }
};
