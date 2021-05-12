/*
����һ�������������ĸ��ڵ� root ����һ������ k ���������һ���㷨�������е� k ����СԪ�أ��� 1 ��ʼ��������
ʾ�� 1��
���룺root = [3,1,4,null,2], k = 1
�����1
ʾ�� 2��
���룺root = [5,3,6,2,4,null,null,1], k = 3
�����3
��ʾ��
���еĽڵ���Ϊ n ��
1 <= k <= n <= 104
0 <= Node.val <= 104
���ף���������������������޸ģ�����/ɾ����������������ҪƵ���ز��ҵ� k С��ֵ���㽫����Ż��㷨��
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        while (root || !s.empty())
        {
            if (root)
            {
                s.push(root);
                root = root->left;
            }
            else
            {
                root = s.top();
                s.pop();
                k--;
                if (k == 0)
                    return root->val;
                root = root->right;
            }
        }
        return -1;
    }
};
