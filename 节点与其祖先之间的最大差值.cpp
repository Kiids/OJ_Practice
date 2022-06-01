/*
�����������ĸ��ڵ� root���ҳ������� ��ͬ �ڵ� A �� B ֮������ֵ V������ V = |A.val - B.val|���� A �� B �����ȡ�
����� A ���κ��ӽڵ�֮һΪ B������ A ���κ��ӽڵ��� B �����ȣ���ô������Ϊ A �� B �����ȣ�
ʾ�� 1��
���룺root = [8,3,10,1,6,null,14,null,null,4,7,13]
�����7
���ͣ� 
�����д����Ľڵ��������ȵĲ�ֵ������һЩ���£�
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
�����п��ܵĲ�ֵ�У����ֵ 7 �� |8 - 1| = 7 �ó���
ʾ�� 2��
���룺root = [1,null,2,null,0,3]
�����3
��ʾ��
���еĽڵ����� 2 �� 5000 ֮�䡣
0 <= Node.val <= 10^5
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
    int ret = 0;
    void DFS(TreeNode* node, int max_val, int min_val)
    {
        if (node == nullptr)
            return;
            
        ret = max(max(abs(node->val - max_val), abs(node->val - min_val)), ret);
        max_val = max(node->val, max_val);
        min_val = min(node->val, min_val);
        DFS(node->left, max_val, min_val);
        DFS(node->right, max_val, min_val);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        DFS(root, root->val, root->val);
        return ret;
    }
};
