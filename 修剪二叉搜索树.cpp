/*
��������������ĸ��ڵ� root ��ͬʱ������С�߽�low �����߽� high��ͨ���޼�������������ʹ�����нڵ��ֵ��[low, high]�С��޼�����Ӧ�øı䱣�������е�Ԫ�ص���Խṹ���������û�б��Ƴ���ԭ�еĸ����Ӵ���ϵ��Ӧ���������� ����֤��������Ψһ�Ĵ𰸡�
���Խ��Ӧ�������޼��õĶ������������µĸ��ڵ㡣ע�⣬���ڵ���ܻ���ݸ����ı߽緢���ı䡣
ʾ�� 1��
���룺root = [1,0,2], low = 1, high = 2
�����[1,null,2]
ʾ�� 2��
���룺root = [3,0,4,null,2,null,null,1], low = 1, high = 3
�����[3,2,null,1]
ʾ�� 3��
���룺root = [1], low = 1, high = 2
�����[1]
ʾ�� 4��
���룺root = [1,null,2], low = 1, high = 3
�����[1,null,2]
ʾ�� 5��
���룺root = [1,null,2], low = 2, high = 4
�����[2]
��ʾ��
���нڵ����ڷ�Χ [1, 104] ��
0 <= Node.val <= 104
����ÿ���ڵ��ֵ����Ψһ��
��Ŀ���ݱ�֤������һ����Ч�Ķ���������
0 <= low <= high <= 104
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root)
            return root;
        if (root->val > high)
            return trimBST(root->left, low, high);
        else if (root->val < low)
            return trimBST(root->right, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
