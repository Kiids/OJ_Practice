/*
��������������ĸ��ڵ� root �������е������ڵ㱻����ؽ��������ڲ��ı���ṹ������£��ָ��������
���ף�ʹ�� O(n) �ռ临�ӶȵĽⷨ������ʵ�֡��������һ��ֻʹ�ó����ռ�Ľ��������
ʾ�� 1��
���룺root = [1,3,null,null,2]
�����[3,1,null,null,2]
���ͣ�3 ������ 1 ���ӣ���Ϊ 3 > 1 ������ 1 �� 3 ʹ������������Ч��
ʾ�� 2��
���룺root = [3,1,4,null,null,2]
�����[2,1,4,null,null,3]
���ͣ�2 ������ 3 ���������У���Ϊ 2 < 3 ������ 2 �� 3 ʹ������������Ч��
��ʾ��
���Ͻڵ����Ŀ�ڷ�Χ [2, 1000] ��
-2^31 <= Node.val <= 2^31 - 1
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
    void recoverTree(TreeNode* root) {
        TreeNode* predecessor=nullptr,* pre=nullptr;
        TreeNode* former=nullptr,* later=nullptr;
        while (root)
        {
            if (root->left)
            {
            	// Ѱ�������������ҽڵ㣨Ҳ���������������ڵ㣩
                // ������������и��ڵ�֮ǰ�ĵ�
                // ��Ϊpredecessor��ǰ�Σ�
                predecessor=root->left;
                while (predecessor->right && predecessor->right != root)
                    predecessor = predecessor->right;
                // ������ڣ�˵��֮ǰ�Ѿ�������ˣ���һ����Ҫ���ţ���Ϊ��Ҫ��ԭ���ṹ
                if (predecessor->right)
                    predecessor->right = nullptr;
                // ���ţ������Ϳ���ֱ���ҵ�root
                else
                {
                    predecessor->right = root;
                    root = root->left;
                    continue;
                }
            }
            // �����еıȽϲ���
            if (pre && pre->val>root->val)
            {
                later = root;
                if (!former)
                    former = pre;
            }
            pre = root;
            root = root->right;
        }
        swap(former->val, later->val);
        return;
    }
};
