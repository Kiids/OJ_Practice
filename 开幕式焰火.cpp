/*
��������ս������Ļʽ��ʼ�ˣ�����������һ�Ŷ������εľ������
����һ�ö����� root ������𣬽ڵ�ֵ��ʾ���������һλ�õ���ɫ���ࡣ���С�ۼ����������ж����ֲ�ͬ����ɫ��
ʾ�� 1��
���룺root = [1,3,2,1,null,2]
�����3
���ͣ�������� 3 ����ͬ����ɫ��ֵ�ֱ�Ϊ 1��2��3
ʾ�� 2��
���룺root = [3,3,3]
�����1
���ͣ�����н����� 1 ����ɫ��ֵΪ 3
��ʾ��
1 <= �ڵ���� <= 1000
1 <= Node.val <= 1000
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
    int numColor(TreeNode* root) {
        unordered_set<int> set;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (cur || s.size())
        {
            while (cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            set.insert(cur->val);
            cur = cur->right;
        }
        return set.size();
    }
};
